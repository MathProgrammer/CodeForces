#include <cstdio>

int main()
{
    int n, k;
    int current_number, previous_number;
    scanf("%d %d", &n, &k);

    for(int i = 1; i <= k + 1; i++)
    {
        if(i == 1)
            current_number = 1;
        else
            current_number = (i%2 == 0 ? k + 2 - previous_number : k + 3 - previous_number);

        printf("%d ", current_number);

        previous_number = current_number;
    }

    for(int i = k + 2; i <= n; i++)
    {
        printf("%d ",i);
    }
    return 0;
}
