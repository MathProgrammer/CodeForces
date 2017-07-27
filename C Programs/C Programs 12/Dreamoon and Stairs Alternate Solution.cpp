#include <cstdio>

int main()
{
    int no_of_steps, multiple;
    scanf("%d %d", &no_of_steps, &multiple);

    int lower_limit = no_of_steps/2 + no_of_steps%2;

    int smallest_multiplier = lower_limit/multiple + (lower_limit%multiple != 0);

    int minimum_number_of_steps = smallest_multiplier*multiple;

    printf("%d\n", (minimum_number_of_steps <= no_of_steps ? minimum_number_of_steps : - 1));
    return 0;
}
