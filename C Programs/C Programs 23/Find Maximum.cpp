#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    vector <int> A(n + 1);
    for(int i = 1; i <= n; i++)
        scanf("%d", &A[i]);

    vector <long long> prefix_sum(n + 1, 0);
    for(int i = 1; i <= n; i++)
        prefix_sum[i] = prefix_sum[i - 1] + A[i];

    const int MAX_N = 1e5 + 5;
    char S[MAX_N];
    scanf("%s", S + 1);

    long long answer = 0, set_bit_sum = 0;

    for(int i = n; i > 0; i--)
    {
        if(S[i] == '1')
        {
            answer = max(answer, set_bit_sum + prefix_sum[i - 1]);

            set_bit_sum += A[i];
        }
    }

    answer = max(answer, set_bit_sum);

    printf("%I64d\n", answer);
    return 0;
}
