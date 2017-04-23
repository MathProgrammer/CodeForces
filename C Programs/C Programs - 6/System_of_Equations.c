#include <stdio.h>

int main()
{
    int n, m, no_of_solutions = 0, i, j;
    scanf("%d %d", &n, &m);

    for(i = 0; i <= m; i++)
    {
        for(j = 0; j <= n; j++)
        {
            if( (i*i + j == n) && (i + j*j == m))
            {
                no_of_solutions++;
            }
        }
    }

    printf("%d\n",no_of_solutions);
    return 0;
}
