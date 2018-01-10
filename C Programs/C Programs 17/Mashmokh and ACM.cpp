#include <cstdio>

const int N = 2001;
long long no_of_sequences[N][N];

int main()
{
    const int MOD = 1e9 + 7;

    int max_number, length;
    scanf("%d %d", &max_number, &length);

    for(int first_number = 1; first_number <= max_number; first_number++)
        no_of_sequences[first_number][1] = 1;

    for(int l = 2; l <= length; l++)
    {
        for(int first_number = 1; first_number <= max_number; first_number++)
        {
            no_of_sequences[first_number][l] = 0;

            for(int i = 1; first_number*i <= max_number; i++)
            {
                no_of_sequences[first_number][l] += no_of_sequences[first_number*i][l - 1];
            }

            no_of_sequences[first_number][l] %= MOD;
        }
    }

    long long answer = 0;
    for(int first_number = 1; first_number <= max_number; first_number++)
        answer += no_of_sequences[first_number][length];

    answer %= MOD;

    printf("%I64d\n", answer);

    return 0;
}
