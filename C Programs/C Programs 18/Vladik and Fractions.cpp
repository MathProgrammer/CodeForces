#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);

    int x = n;
    int y = n + 1;
    int z = n*(n + 1);

    printf("%d %d %d\n", x, y, z);
    return 0;
}
