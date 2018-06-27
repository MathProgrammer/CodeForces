#include <cstdio>
#include <vector>
#include <limits>

using namespace std;
typedef long long LL;

int overflow(LL a, LL b)
{
    return ( ((a*b)/b) != a);
}

int main()
{
    int no_of_elements, k;
    scanf("%d %d", &no_of_elements, &k);

    vector <long long> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++) scanf("%I64d", &A[i]);

    vector <long long> sum(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
        sum[i] = sum[i - 1] + A[i];

    vector <int> next_non_1(no_of_elements + 1);
    next_non_1[no_of_elements] = no_of_elements + 1;
    for(int i = no_of_elements - 1; i >= 1; i--)
        next_non_1[i] = (A[i + 1] != 1 ? i + 1 : next_non_1[i + 1]);

    int good_segments = 0;

    for(int left = 1; left <= no_of_elements; left++)
    {
        LL product = 1;

        for(int right = left; right <= no_of_elements && !overflow(product, A[right]); right = next_non_1[right])
        {
            LL sum_here = sum[right] - sum[left - 1];
            product *= A[right];

            LL required_sum = 0;

            if(product%k == 0) required_sum = product/k;

            LL ones_in_middle = next_non_1[right] - (right + 1);

            if(sum_here <= required_sum && required_sum <= sum_here + ones_in_middle)
                good_segments++;
        }
    }

    printf("%d\n", good_segments);
    return 0;
}
