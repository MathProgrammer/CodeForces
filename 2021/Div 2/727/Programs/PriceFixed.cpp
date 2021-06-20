#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sort_by_second(pair <long long, long long> &P, pair <long long, long long> &Q)
{
    if(P.second == Q.second)
    {
        return (P.first > Q.first);
    }

    return (P.second > Q.second);
}

int main()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector <pair <long long, long long> > A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i].first >> A[i].second;
    }

    sort(A.begin() + 1, A.end(), sort_by_second);
    /*for(int i = 1; i <= no_of_elements; i++)
    {
        cout << A[i].first << " " << A[i].second << "\n";
    }*/

    long long total = 0, cost = 0;
    for(int left = 1, right = no_of_elements; left <= right; )
    {
        if(total >= A[right].second)
        {
            cost += A[right].first;
            total += A[right].first; //cout << "Buying R = " << right << " Cost = " << cost << " Total = " << total << "\n";

            right--;
            continue;
        }

        if(total + A[left].first < A[right].second)
        {
            cost += 2*A[left].first;
            total += A[left].first; //cout << "Buying L = " << left << " Cost = " << cost << " Total = " << total << "\n";

            left++;
            continue;
        }

        long long remaining_2 = A[right].second - total;

        cost += 2*remaining_2;
        total += remaining_2; //cout << "Buying L = " << left << " Cost = " << cost << " Total = " << total;

        A[left].first -= remaining_2; //cout << " New Left = " << A[left].first << "\n";
    }

    cout << cost << "\n";
    return 0;
}
