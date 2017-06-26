#include <cstdio>

int main()
{
    const int MOD = 1e9 + 7;
    int X, Y, number_of_terms;
    long long answer;

    scanf("%d %d %d", &X, &Y, &number_of_terms);

    X = (X + MOD)%MOD;
    Y = (Y + MOD)%MOD;

    switch(number_of_terms%6)
    {
        case 1: answer = X; break;

        case 2: answer = Y; break;

        case 3: answer = Y + MOD - X; break;

        case 4: answer = 0 + MOD - X; break;

        case 5: answer = 0 + MOD - Y; break;

        case 0: answer = X + MOD - Y; break;
    }

    answer = (answer + MOD)%MOD; //In case it's negative

    printf("%I64d\n",answer);
    return 0;
}
