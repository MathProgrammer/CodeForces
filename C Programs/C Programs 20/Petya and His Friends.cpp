#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);

    if(n == 2)
    {
        printf("-1\n");
        return 0;
    }

    printf("6\n10\n15\n");
    for(int i = 4; i <= n; i++)
    {
        printf("6"); for(int zero = 1; zero <= i - 4 + 1; zero++) printf("0");
        printf("\n");
    }
    return 0;
}
