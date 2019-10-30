#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_elements;
    long long no_of_operations;
    cin >> no_of_elements >> no_of_operations;

    vector <long long> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }

    sort(all(A));

    vector <long long> sum_till(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        sum_till[i] = sum_till[i - 1] + A[i];
    }

    vector <long long> sum_from(no_of_elements + 2, 0);
    for(int i = no_of_elements; i >= 1; i--)
    {
        sum_from[i] = sum_from[i + 1] + A[i];
    }

    long long best_minimum = A[no_of_elements] - A[1];
    for(int i = 1; i <= no_of_elements; i++)
    {
        if(i*A[i] - sum_till[i] + sum_from[i + 1] - (no_of_elements - i)*A[i] <= no_of_operations)
        {
            best_minimum = 0;
            break;
        }
    }

    for(int i = 1; i <= no_of_elements; i++)
    {
        long long operations_used_in_prefix = i*A[i] - sum_till[i];

        if(operations_used_in_prefix > no_of_operations)
        {
            continue;
        }

        //Maintain the invariant that it is always possible to make the suffix of the array = Right
        long long left = A[i], right = A[no_of_elements];
        while(right - left > 1)
        {
            long long mid = (right + left)/2;

            int pos = upper_bound(A.begin(), A.end(), mid - 1) - A.begin(); //Make suffix = mid

            long long operations_used_in_suffix = sum_from[pos] - (no_of_elements - pos + 1)*mid;

            if(operations_used_in_prefix + operations_used_in_suffix <= no_of_operations)
            {
                right = mid;
            }
            else
            {
                left = mid;
            }
        }

        best_minimum = min(best_minimum, right - A[i]);
    }

    for(int i = no_of_elements; i >= 1; i--)
    {
        long long operations_used_in_suffix = sum_from[i] - (no_of_elements - i + 1)*A[i];

        if(operations_used_in_suffix > no_of_operations)
        {
            continue;
        }

        //Maintain the invariant that it is always possible to make the prefix of array = Left
        long long left = A[1], right = A[i];
        while(right - left > 1)
        {
            long long mid = (left + right)/2;

            int pos = upper_bound(A.begin(), A.end(), mid) - A.begin() - 1; //Make Prefix = Mid

            long long operations_used_in_prefix = pos*mid - sum_till[pos];

            if(operations_used_in_suffix + operations_used_in_prefix <= no_of_operations)
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }

        best_minimum = min(best_minimum, A[i] - left);
    }

    cout << best_minimum << "\n";
    return 0;
}
