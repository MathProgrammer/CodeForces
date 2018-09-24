#include <cstdio>

int main()
{
    long long left, right;
    scanf("%I64d %I64d", &left, &right);

    printf("YES\n");
    for(long long i = left; i <= right; i += 2)
        printf("%I64d %I64d\n", i, i + 1);

    return 0;
}
