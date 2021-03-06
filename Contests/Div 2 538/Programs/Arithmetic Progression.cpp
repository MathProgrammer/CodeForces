#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()
using namespace std;

mt19937 rng(time(NULL));

int find_maximum(int &queries)
{
    int left = 0, right = 1e9 + 5;

    //Always L < Max <= R
    while(right - left > 1)
    {
        int has_higher;
        int mid = (left + right)/2;

        queries--;

        cout << "> " << mid << "\n"; cout.flush();

        cin >> has_higher;

        if(has_higher)
            left = mid;
        else
            right = mid;
    }

    return right;
}

int find_difference(int &queries, int greatest, int no_of_elements)
{
    int remaining_range = no_of_elements - 1;
    vector <int> A;

    vector <int> asked(no_of_elements + 1, false);

    while(queries > 0 && remaining_range > 0)
    {
        int question_index = uniform_int_distribution<int>(1, no_of_elements)(rng);

        if(asked[question_index])
        {
            continue;
        }

        cout << "? " << question_index << "\n"; cout.flush();

        asked[question_index] = true;

        int answer;
        cin >> answer;
        A.push_back(answer);

        queries--;
        remaining_range--;
    }

    sort(all(A));

    if(A[A.size() - 1] != greatest)
        A.push_back(greatest);

    int difference = A[1] - A[0];

    for(int i = 1; i < A.size(); i++)
        difference = __gcd(difference, A[i] - A[i - 1]);

    return difference;
}

int main()
{
    int no_of_elements;
    cin >> no_of_elements;

    const int MAX_QUERIES = 60;
    int queries = MAX_QUERIES;

    int maximum = find_maximum(queries);
    int difference = find_difference(queries, maximum, no_of_elements);

    int minimum = maximum - difference*(no_of_elements - 1);

    cout << "! " << minimum << " " << difference << "\n"; cout.flush();

    return 0;
}
