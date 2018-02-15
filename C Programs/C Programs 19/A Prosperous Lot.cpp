#include <cstdio>

int main()
{
    int no_of_loops;
    scanf("%d", &no_of_loops);

    const int MAX_LOOPS = 36;

    if(no_of_loops > MAX_LOOPS)
    {
        printf("-1\n");
        return 0;
    }

    while(no_of_loops >= 2)
    {
        printf("8");
        no_of_loops -= 2;
    }

    if(no_of_loops == 1)
        printf("9\n");

    return 0;
}

