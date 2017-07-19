#include <cstdio>

int main()
{
    long long left, right;
    scanf("%I64d %I64d", &left, &right);

    long long range = right - (left - 1);
    if(range < 3 || (left%2 == 1 && range < 4))
    {
        printf("-1\n");
    }
    else
    {
        if(left%2 == 0)
            printf("%I64d %I64d %I64d", left, left + 1, left + 2);
        else
            printf("%I64d %I64d %I64d", left + 1, left + 2, left + 3);
    }

    return 0;
}
