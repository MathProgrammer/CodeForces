#include <cstdio>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    for(int i = 1; i <= k ; i++)
        printf("%d ", n - (i - 1));

    for(int i = 1; i + k <= n; i++)
        printf("%d ", i);

    return 0;
}
