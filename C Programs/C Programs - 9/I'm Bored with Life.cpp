#include <cstdio>

#define min(a, b) (a < b ? a : b)

int factorial(int n)
{
    int fact = 1;

    while(n > 0)
    {
        fact *= n;
        n--;
    }

    return fact;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%d\n", factorial(min(a, b)));
    return 0;
}
