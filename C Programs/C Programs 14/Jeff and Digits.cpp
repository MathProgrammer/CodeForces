#include <cstdio>

int main()
{
    int no_of_digits;
    scanf("%d", &no_of_digits);

    int no_of_5s = 0, no_of_0s = 0;
    for(int i = 1; i <= no_of_digits; i++)
    {
        int digit;
        scanf("%d", &digit);

        no_of_5s += (digit == 5);
        no_of_0s += (digit == 0);
    }

    if(no_of_0s == 0)
    {
        printf("-1\n");
    }
    else if(no_of_5s < 9)
    {
        printf("0\n");
    }
    else
    {
        int no_of_5s_in_number = (no_of_5s/9)*9;
        for(int i = 1; i <= no_of_5s_in_number; i++)
            printf("5");

        for(int i = 1; i <= no_of_0s; i++)
            printf("0");
    }

    return 0;
}
