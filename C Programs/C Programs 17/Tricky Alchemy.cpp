#include <cstdio>

#define max(a, b) (a > b ? a : b)

int main()
{
    int yellow, blue;
    scanf("%d %d", &yellow, &blue);

    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);

    long long required_yellow = 2LL*x + y;
    long long required_blue = y + 3LL*z;

    long long required = max(0LL, required_yellow - yellow) + max(0LL, required_blue - blue);
    printf("%I64d\n", required);

    return 0;
}
