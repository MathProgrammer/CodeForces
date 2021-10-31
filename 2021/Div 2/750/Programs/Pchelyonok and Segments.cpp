#include <iostream>
#include <vector>

using namespace std;

long long get_largest_k(long long n)
{
    long long right = n, left = 1;

    while(right - left > 1)
    {
        long long mid = (left + right)/2;

        if(mid*1LL*(mid + 1) <= 2*n)
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }

    return left;
}

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector <long long> A(no_of_elements + 5, 0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }

    vector <long long> sum_from(no_of_elements + 5, 0);
    for(int i = no_of_elements; i >= 1; i--)
    {
        sum_from[i] = A[i] + sum_from[i + 1];
    }

    long long max_k = get_largest_k(no_of_elements);

    vector <vector <long long> > max_segment_sum(no_of_elements + 5, vector <long long> (max_k + 1));
    for(int i = no_of_elements; i >= 1; i--)
    {
        for(int segment_size = 1; segment_size <= max_k; segment_size++)
        {
            max_segment_sum[i][segment_size] = max_segment_sum[i + 1][segment_size];

            if(i + segment_size - 1 > no_of_elements)
            {
                continue;
            }

            long long sum_here = sum_from[i] - sum_from[i + segment_size];

            if(segment_size == 1 || sum_here < max_segment_sum[i + segment_size][segment_size - 1])
            {
                max_segment_sum[i][segment_size] = max(max_segment_sum[i][segment_size], sum_here);
            }
        }
    }

    int answer = 0;
    for(int segment_size = max_k; segment_size >= 1; segment_size--)
    {
        if(max_segment_sum[1][segment_size] > 0)
        {
            answer = segment_size;
            break;
        }
    }

    cout << answer << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
