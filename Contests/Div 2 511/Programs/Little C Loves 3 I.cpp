#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);

    if(n%3 == 2)
    {
        printf("%d %d %d\n", 1, 2, n - 3);
    }
    else
    {
        printf("%d %d %d\n", 1, 1, n - 2);
    }

    return 0;
}
