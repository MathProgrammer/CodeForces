#include <cstdio>

int main()
{
    int no_of_children, no_of_candies_given;
    scanf("%d %d", &no_of_children, &no_of_candies_given);

    int maximum_turns = 0, last_child = 0;
    for(int i = 1; i <= no_of_children; i++)
    {
        int candy_i;
        scanf("%d", &candy_i);

        int no_of_turns = candy_i/no_of_candies_given + (candy_i%no_of_candies_given != 0);

        if(no_of_turns >=  maximum_turns)
        {
            maximum_turns = no_of_turns;
            last_child = i;
        }
    }

    printf("%d\n", last_child);
    return 0;
}
