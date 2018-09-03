#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

#define all(v) (v).begin() + 1, (v).end()
using namespace std;

int main()
{
    int no_of_elements, median_target;
    cin >> no_of_elements >> median_target;

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
        cin >> A[i];

    sort(all(A));

    int middle = no_of_elements/2 + 1;
    long long no_of_operations = 0;

    for(int i = 1; i <= no_of_elements; i++)
    {
        if(i < middle)
        {
            no_of_operations += max(0, A[i] - median_target);
        }
        else if(i == middle)
        {
            no_of_operations += abs(A[i] - median_target);
        }
        else if(i > middle)
        {
            no_of_operations += max(0, median_target - A[i]);
        }
    }

    cout << no_of_operations;
    return 0;
}

