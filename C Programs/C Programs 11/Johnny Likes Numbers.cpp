#include <cstdio>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int next_multiple = n + (k - n%k);
    printf("%d\n", next_multiple);

    return 0;
}
