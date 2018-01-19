#include <cstdio>

#define min(a, b) (a < b ? a : b)

int main()
{
    int n, length;
    scanf("%d %d", &n, &length);

    int ans = 1e9;
    for(int i = 1; i <= n; i++)
    {
        int a_i;
        scanf("%d", &a_i);

        if(length%a_i == 0)
            ans = min(ans, length/a_i);
    }

    printf("%d\n", ans);
    return 0;
}

