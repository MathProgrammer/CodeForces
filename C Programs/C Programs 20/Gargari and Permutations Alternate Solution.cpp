#include <cstdio>

#define max(a, b) (a > b ? a : b)

const int MAX_N = 1005, MAX_PERMUTATIONS = 5;
int P[MAX_PERMUTATIONS + 1][MAX_N], maximum_length_till[MAX_N];
int position[MAX_PERMUTATIONS + 1][MAX_N];

int main()
{
    int no_of_permutations, length;
    scanf("%d %d", &length, &no_of_permutations);

    for(int k = 1; k <= no_of_permutations; k++)
    {
        for(int i = 1; i <= length; i++)
        {
            scanf("%d", &P[k][i]);
            int element = P[k][i];
            position[k][element] = i;
        }
    }

    int answer = 1;

    for(int i = 1; i <= length; i++)
    {
        maximum_length_till[i] = 1;

        for(int j = 1; j < i; j++)
        {
            int current = P[1][i], previous = P[1][j];
            int previous_always_before_current = true;

            for(int k = 1; k <= no_of_permutations; k++)
            {
                if(position[k][previous] > position[k][current])
                {
                    previous_always_before_current = false;
                }
            }

            if(previous_always_before_current)
            {
                maximum_length_till[i] = max(maximum_length_till[i], 1 + maximum_length_till[j]);
            }
        }

        answer = max(answer, maximum_length_till[i]);
    }

    printf("%d\n", answer);
    return 0;
}


