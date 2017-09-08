#include <cstdio>

int main()
{
    int no_of_1s, no_of_0s;
    scanf("%d %d", &no_of_0s, &no_of_1s);

    if(no_of_1s > 2*(no_of_0s + 1) || no_of_0s > no_of_1s + 1)
    {
        printf("-1\n");
        return 0;
    }

    while(no_of_0s > 0 && no_of_1s > 0)
    {
        if(no_of_1s > no_of_0s)
        {
            printf("110");
            no_of_1s -= 2, no_of_0s--;
        }
        else if(no_of_1s == no_of_0s)
        {
            printf("10");
            no_of_0s--, no_of_1s--;
        }
        else if(no_of_1s < no_of_0s)
        {
            printf("01");
            no_of_0s--, no_of_1s--;
        }
    }

    for(int i = 1; i <= no_of_0s; i++) printf("0");
    for(int i = 1; i <= no_of_1s; i++) printf("1");

    return 0;
}
