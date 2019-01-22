#include <cstdio>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7, SIZE = 3;

void load_identity(long long I[][SIZE])
{
    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            I[i][j] = (i == j ? 1 : 0);
}

void copy(long long source[][SIZE], long long target[][SIZE])
{
    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            target[i][j] = source[i][j];
}

void multiply(long long A[][SIZE], long long B[][SIZE])
{
    long long product[SIZE][SIZE];

    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            product[i][j] = 0;

            for(int k = 0; k < SIZE; k++)
            {
                product[i][j] += (A[i][k]*B[k][j])%MOD;
            }

            product[i][j] %= MOD;
        }
    }

    copy(product, A);
}

void power(long long X[][SIZE], long long power)
{
    long long result[SIZE][SIZE];
    load_identity(result);

    while(power)
    {
        if(power%2 == 1)
            multiply(result, X);

        multiply(X, X);
        power = power >> 1;
    }

    copy(result, X);
}

int get_count(int limit, int remainder)
{
    if(remainder == 0)
        return limit/3;
    else
        return (limit/3 + (limit%3 >= remainder));
}

int main()
{
    int no_of_elements, left, right;
    scanf("%d %d %d", &no_of_elements, &left, &right);

    vector <long long> frequency(3, 0);

    for(int i = 0; i < 3; i++)
    {
        frequency[i] = get_count(right, i) - get_count(left - 1, i);
    }

    int no_of_ways_sum_0_from_0_elements = 1, no_of_ways_sum_1_from_0_elements = 0, no_of_ways_sum_2_from_0_elements = 0;

  /*f(i, 0) = F[0]f(i - 1, 0) + F[2]f(i - 1, 1) + F[1]f(i - 1, 2);
    f(i, 1) = F[1]f(i - 1, 0) + F[0]f(i - 1, 1) + F[2]f(i - 1, 2);
    f(i, 2) = F[2]f(i - 1, 0) + F[1]f(i - 1, 1) + F[0]f(i - 1, 2);*/

    long long A[SIZE][SIZE] = {{no_of_ways_sum_0_from_0_elements, no_of_ways_sum_1_from_0_elements, no_of_ways_sum_2_from_0_elements}};

    long long F[SIZE][SIZE] = { {frequency[0], frequency[1], frequency[2]},
                                {frequency[2], frequency[0], frequency[1]},
                                {frequency[1], frequency[2], frequency[0]} };

    //A^n = A^{n - 1}F = A^1 F^{n-1}

    power(F, no_of_elements);

    multiply(A, F);

    printf("%I64d\n", A[0][0]);
    return 0;
}
