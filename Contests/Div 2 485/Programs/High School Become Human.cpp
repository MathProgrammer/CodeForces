#include <cstdio>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

int main()
{
    long long x, y;
    scanf("%I64d %I64d", &x, &y);

    if(x == y || (min(x, y) == 2 && max(x, y) == 4))
    {
        printf("=");
    }
    else if(min(x, y) == 1)
    {
        printf(x == 1 ? "<" : ">");
    }
    else if(min(x, y) == 2)
    {
        if(x == 2)
        {
            printf(y < 4 ? "<" : ">");
        }
        else if(y == 2)
        {
            printf(x < 4? ">" : "<");
        }
    }
    else if(min(x, y) >= 3) //Both greater than e
    {
        printf(x < y ? ">" : "<");
    }
    return 0;
}
