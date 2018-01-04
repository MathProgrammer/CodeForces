#include <cstdio>

int main()
{
    int no_of_queries;
    scanf("%d", &no_of_queries);

    while(no_of_queries--)
    {
        int n;
        scanf("%d", &n);

        int no_of_parts = -1;

        if( !(n <= 3 || n == 5 || n == 7 || n == 11) )
        {
            switch(n%4)
            {
                case 0: no_of_parts = n/4; break;
                case 1: no_of_parts = (n - 9)/4 + 1; break;
                case 2: no_of_parts = (n - 6)/4 + 1; break;
                case 3: no_of_parts = (n - 15)/4 + 2; break;
            }
        }

        printf("%d\n", no_of_parts);
    }
    return 0;
}
