#include <cstdio>

int main()
{
    int N, k;
    scanf("%d %d", &N, &k);

    int special_table[N + 1][N + 1];
    int front_ptr = 1, back_ptr = N*N;

    for(int row = 1; row <= N; row++)
    {
        for(int column = N; column >= k; column--)
            special_table[row][column] = back_ptr--;

        for(int column = 1; column < k; column++)
            special_table[row][column] = front_ptr++;
    }

    int k_column_sum = 0;


    for(int row = 1; row <= N; row++)
        k_column_sum += special_table[row][k];

    printf("%d\n", k_column_sum);

    for(int row = 1; row <= N; row++)
    {
        for(int column = 1; column <= N; column++)
        {
            printf("%d ", special_table[row][column]);
        }
        printf("\n");
    }

    return 0;
}
