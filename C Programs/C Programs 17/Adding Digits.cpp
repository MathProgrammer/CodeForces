#include <cstdio>

int main()
{
    int a, b, no_of_operations;
    scanf("%d %d %d", &a, &b, &no_of_operations);

    int appended_digit = -1;
    for(int digit = 0; digit <= 9; digit++)
    {
        if((a*10 + digit)%b == 0)
        {
            appended_digit = digit;
            break;
        }
    }

    if(appended_digit == -1)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d%d", a, appended_digit);
        for(int i = 2; i <= no_of_operations; i++) printf("0");
    }

    return 0;
}
