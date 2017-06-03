#include <stdio.h>
#define MAX_SIZE 50

int main()
{
    long long equivalent_number = 0LL;
    int no_of_balls, i;
    char stack[MAX_SIZE + 1];

    scanf("%d %s", &no_of_balls, stack);

    for(i = 0; i < no_of_balls; i++)
        if(stack[i] == 'B')
            equivalent_number = equivalent_number| (1LL << i);

    printf("%I64d\n",equivalent_number);
    return 0;
}
