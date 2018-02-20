#include <cstdio>
#include <vector>

using namespace std;

long long power(long long n, long long power, int MOD)
{
    long long result = 1;

    while(power)
    {
        if(power%2 == 1)
            result = (result*n)%MOD;

        n = (n*n)%MOD;
        power = power >> 1;
    }

    return result;
}

long long inverse(long long n, long long m)
{
    return power(n, m - 2, m);
}

long long choose_2(long long n)
{
    return (n*(n - 1))/2;
}

int main()
{
    const int MOD = 1e9 + 7;

    int length, no_of_alphabets;
    scanf("%d %d", &length, &no_of_alphabets);

    vector <int> A(length + 1);
    for(int i = 1; i <= length; i++) scanf("%d", &A[i]);

    vector <int> B(length + 1);
    for(int i = 1; i <= length; i++) scanf("%d", &B[i]);

    int no_of_zeroes = 0;
    for(int i = 1; i <= length; i++) no_of_zeroes += (A[i] == 0) + (B[i] == 0);

    const int ANY_WAY = 0, GREATER = 1;
    typedef vector <long long> v_ll;
    vector <v_ll> no_of_ways(length + 5, v_ll(2, 1));

    no_of_ways[length + 1][ANY_WAY] = 1;
    no_of_ways[length + 1][GREATER] = 0;

    for(int i = length; i >= 1; i--)
    {
        no_of_ways[i][ANY_WAY] = no_of_ways[i + 1][ANY_WAY];

        if(A[i] == 0) no_of_ways[i][ANY_WAY] = (no_of_ways[i][ANY_WAY]*no_of_alphabets)%MOD;
        if(B[i] == 0) no_of_ways[i][ANY_WAY] = (no_of_ways[i][ANY_WAY]*no_of_alphabets)%MOD;

        if(A[i] == 0 && B[i] == 0)
        {
            long long choose_different_alphabets = choose_2(no_of_alphabets);
            long long choose_same_alphabet = no_of_alphabets;

            no_of_ways[i][GREATER] = choose_different_alphabets*no_of_ways[i + 1][ANY_WAY] + choose_same_alphabet*no_of_ways[i + 1][GREATER];
        }
        else if(A[i] == 0)
        {
            no_of_ways[i][GREATER] = (no_of_alphabets - B[i])*no_of_ways[i + 1][ANY_WAY] + no_of_ways[i + 1][GREATER];
        }
        else if(B[i] == 0)
        {
            no_of_ways[i][GREATER] = (A[i] - 1)*no_of_ways[i + 1][ANY_WAY] + no_of_ways[i + 1][GREATER];
        }
        else if(A[i] > B[i])
        {
            no_of_ways[i][GREATER] = no_of_ways[i + 1][ANY_WAY];
        }
        else if(A[i] == B[i])
        {
            no_of_ways[i][GREATER] = no_of_ways[i + 1][GREATER];
        }
        else if(A[i] < B[i])
        {
            no_of_ways[i][GREATER] = 0;
        }

        no_of_ways[i][ANY_WAY] %= MOD;
        no_of_ways[i][GREATER] %= MOD;
    }

    long long numerator = no_of_ways[1][GREATER];
    long long denominator = power(no_of_alphabets, no_of_zeroes, MOD);

    long long answer = numerator*inverse(denominator, MOD);
    answer %= MOD;

    printf("%I64d\n", answer);

    return 0;
}
