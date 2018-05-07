#include <cstdio>

int main()
{
    int n, no_of_operations;
    scanf("%d %d", &n, &no_of_operations);

    while(no_of_operations--)
    {
        n = (n%10 == 0 ? n/10 : n - 1);
    }

    printf("%d\n", n);
    return 0;
}
