#include <cstdio>
#include <vector>

using namespace std;

const int MAX = 1e3 + 5, MOD = 998244353;
long long choose[MAX][MAX];

void precompute()
{
    for(int n = 0; n < MAX; n++)
    {
        for(int r = 0; r <= n; r++)
        {
            if(r == 0 || r == n)
                choose[n][r] = 1;
            else
                choose[n][r] = (choose[n - 1][r] + choose[n - 1][r - 1])%MOD;
        }
    }
}

int main()
{
    precompute();

    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
        scanf("%d", &A[i]);

    vector <long long> answer_from(no_of_elements + 2, 0);
    answer_from[no_of_elements + 1] = 1;

    for(int i = no_of_elements; i >= 1; i--)
    {
        if(A[i] <= 0)
        {
            answer_from[i] = 0;
            continue;
        }

        for(int j = i + A[i]; j <= no_of_elements; j++)
        {
            answer_from[i] += (choose[j - i][A[i]]*answer_from[j + 1])%MOD;
        }

        answer_from[i] %= MOD;
    }

    long long answer = 0;
    for(int i = 1; i <= no_of_elements; i++)
        answer += answer_from[i];

    printf("%I64d\n", answer%MOD);
    return 0;
}
