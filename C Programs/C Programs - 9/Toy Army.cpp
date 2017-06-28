#include <cstdio>

int main()
{
    int number_of_soldiers, killed;
    scanf("%d", &number_of_soldiers);

    killed = 3*((number_of_soldiers + 1)/2);
    printf("%d\n", killed);
    return 0;
}
