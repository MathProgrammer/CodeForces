#include <cstdio>

using namespace std;

int main()
{
    int number_of_digits, multiple;
    scanf("%d %d", &number_of_digits, &multiple);

    if(number_of_digits == 1 && multiple == 10)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d", multiple);

        int no_of_zeroes = (multiple == 10 ? number_of_digits - 2 : number_of_digits - 1);

        for(int zero_count = 1; zero_count <= no_of_zeroes; zero_count++)
            printf("0");
    }

    printf("\n");
    return 0;
}
