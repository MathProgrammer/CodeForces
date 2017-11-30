#include <cstdio>

int main()
{
    int rows, columns;
    scanf("%d %d", &rows, &columns);

    for(int i = 1; i <= rows; i++)
    {
        int different_cell = -1;
        char default_char = (i%2 == 0 ? '.' : '#');

        if(i%2 == 0)
            different_cell = (i%4 == 0 ? 1 : columns);

        for(int j = 1; j <= columns; j++)
            printf("%c", (j != different_cell ? default_char : '#'));

        printf("\n");
    }
    return 0;
}
