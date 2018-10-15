#include <cstdio>

int main()
{
    int n, d;
    scanf("%d %d", &n, &d);

    int no_of_grasshoppers;
    scanf("%d", &no_of_grasshoppers);

    while(no_of_grasshoppers--)
    {
        int x, y;
        scanf("%d %d", &x, &y);

        printf(-d <= x - y && x - y <= d && d <= x + y && x + y <= 2*n - d ? "YES\n" : "NO\n");
    }

    return 0;
}
