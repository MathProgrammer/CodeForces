#include <cstdio>

int main()
{
    int no_of_drinks;
    scanf("%d", &no_of_drinks);

    double numerator = 0.0;
    for(int i = 1; i <= no_of_drinks; i++)
    {
        int percent_i;
        scanf("%d", &percent_i);

        numerator += percent_i;
    }

    double denominator = no_of_drinks*1.0;
    double fraction = numerator/denominator;

    printf("%lf\n", fraction);
    return 0;
}
