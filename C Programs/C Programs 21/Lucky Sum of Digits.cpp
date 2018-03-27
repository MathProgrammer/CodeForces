#include <cstdio>

int main()
{
    int sum;
    scanf("%d", &sum);

    int possible = false;
    int no_of_4s = 0, no_of_7s = sum/7;

    while(no_of_7s >= 0)
    {
        if( (sum - 7*no_of_7s)%4 == 0)
        {
            no_of_4s = (sum - 7*no_of_7s)/4;
            possible = true;
            break;
        }
        no_of_7s--;
    }

    if(!possible)
    {
        printf("-1\n");
        return 0;
    }

    for(int i = 1; i <= no_of_4s; i++) printf("4");
    for(int i = 1; i <= no_of_7s; i++) printf("7");

    return 0;
}
