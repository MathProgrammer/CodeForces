#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);

    for(int row = 0; row <= n; row++)
    {
        for(int space = 0; space < n - row; space++)
            printf("  ");

        for(int number = 0; number <= row; number++)
            if(row == 0)
                printf("%d", number);
            else
                printf("%d ", number);

        for(int number = row - 1; number >= 0; number--)
            if(number == 0)
                printf("%d", number);
            else
                printf("%d ", number);

        printf("\n");
    }

    for(int row = n - 1; row >= 0; row--)
    {
        for(int space = 0; space < n - row; space++)
            printf("  ");

        for(int number = 0; number <= row; number++)
            if(row == 0)
                printf("%d", number);
            else
                printf("%d ", number);

        for(int number = row - 1; number >= 0; number--)
            if(number == 0)
                printf("%d", number);
            else
                printf("%d ", number);

        printf("\n");
    }

    return 0;
}
