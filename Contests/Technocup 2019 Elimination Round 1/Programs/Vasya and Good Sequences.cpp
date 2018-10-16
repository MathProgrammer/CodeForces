#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int population_count(long long n)
{
    int no_of_1s = 0;

    while(n)
    {
        if(n%2 == 1)
            no_of_1s++;

        n = n >> 1;
    }

    return no_of_1s;
}

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <long long> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        scanf("%I64d", &A[i]);

        A[i] = population_count(A[i]);
    }

    vector <long long> sum(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
        sum[i] = sum[i - 1] + A[i];

    long long good_sequences = 0;
    long long odd_sums = 0;
    long long even_sums = 1;

    for(int i = 1; i <= no_of_elements; i++)
    {
        if(sum[i]%2 == 0)
        {
            good_sequences += even_sums;

            even_sums++;
        }
        else
        {
            good_sequences += odd_sums;

            odd_sums++;
        }
    }

    long long bad_sequences = 0;
    for(int left = 1; left <= no_of_elements; left++)
    {
        const int MAX_RANGE = 128;

        long long maximum_element = A[left];

        for(int right = left; right <= min(no_of_elements, left + MAX_RANGE); right++)
        {
            int sum_here = sum[right] - sum[left - 1];
            maximum_element = max(maximum_element, A[right]);

            if(sum_here%2 == 0 && 2*maximum_element > sum_here)
            {
                bad_sequences++;
            }
        }
    }

    good_sequences -= bad_sequences;

    printf("%I64d\n", good_sequences);
    return 0;
}
