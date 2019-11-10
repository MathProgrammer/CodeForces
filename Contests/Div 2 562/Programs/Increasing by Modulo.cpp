#include <iostream>
#include <vector>

using namespace std;

int possible(int operations, int m, vector <int> &A)
{
    int minimum = 0;

    for(int i = 1; i < A.size(); i++)
    {
        if( (A[i] <= minimum && A[i] + operations >= minimum) || (A[i] > minimum && A[i] + operations - m >= minimum) )
            continue;

        if(A[i] < minimum)
            return false;

        minimum = A[i];
    }

    return true;
}

int main()
{
    int no_of_elements, m;
    cin >> no_of_elements >> m;

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
        cin >> A[i];

    int left = -1, right = m;
    while(right - left > 1)
    {
        int mid = (left + right)/2;

        if(possible(mid, m, A))
            right = mid;
        else
            left = mid;
    }

    cout << right;
    return 0;
}
