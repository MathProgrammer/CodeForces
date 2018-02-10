#include <cstdio>

int main()
{
    int no_of_rows;
    scanf("%d", &no_of_rows);

    int maximum_pieces = (no_of_rows)*(no_of_rows/2) + (no_of_rows%2)*(no_of_rows/2 + no_of_rows%2);
    printf("%d\n", maximum_pieces);

    for(int i = 1; i <= no_of_rows; i++)
    {
        if(i%2 == 1)
        {
            for(int j = 1; j <= no_of_rows; j++)
                printf("%c", j%2 == 0 ? '.' : 'C');
        }
        else
        {
            for(int j = 1; j <= no_of_rows; j++)
                printf("%c", j%2 == 0 ? 'C' : '.');
        }

        printf("\n");
    }

    return 0;
}
