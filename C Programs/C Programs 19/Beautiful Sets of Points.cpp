#include <cstdio>
#define min(a, b) (a < b ? a : b)

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    int limit = min(m, n) + 1;
    printf("%d\n", limit);

    for(int i = 0; i < limit; i++)
        printf("%d %d\n", i, limit - i - 1);

    return 0;
}
