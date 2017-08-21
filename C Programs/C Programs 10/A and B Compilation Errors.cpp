#include <cstdio>

int main()
{
    int no_of_errors, error_i;
    scanf("%d", &no_of_errors);

    int sum_1 = 0;
    for(int i = 1; i <= no_of_errors; i++)
    {
        scanf("%d", &error_i);
        sum_1 += error_i;
    }

    //Second List
    int sum_2 = 0;
    for(int i = 1; i <= no_of_errors - 1; i++)
    {
        scanf("%d", &error_i);
        sum_2 += error_i;
    }

    int sum_3 = 0;
    for(int i = 1; i <= no_of_errors - 2; i++)
    {
        scanf("%d", &error_i);
        sum_3 += error_i;
    }


    printf("%d \n%d\n", sum_1-sum_2, sum_2 - sum_3);
    return 0;
}
