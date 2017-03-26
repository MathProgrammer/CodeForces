#include <stdio.h>
#include <stdlib.h>

short find_minimum_stones_to_be_removed(char *);
int main()
{
    short no_of_stones, minimum_stones_to_be_removed;
    scanf("%hu",&no_of_stones);

    char *colour_of_stones = malloc((no_of_stones+1)*sizeof(char));
    scanf("%s",colour_of_stones);

    minimum_stones_to_be_removed = find_minimum_stones_to_be_removed(colour_of_stones);
    printf("%hu\n",minimum_stones_to_be_removed);

    free(colour_of_stones);
    return 0;
}

short find_minimum_stones_to_be_removed(char *colour_of_stones)
{
    short i, j, stones_to_remove = 0;
    char current_colour;

    for(i = 0; *(colour_of_stones + i) != '\0'; )
    {
        current_colour = *(colour_of_stones + i);

        //Counts the number of stones of the same colour as stone i, after stone i
        for(j = i + 1; *(colour_of_stones + j) == current_colour ; j++)
        {
            stones_to_remove++;
        }

        //All the stones that j ran through has been removed. i needs to resume counting from where j ended.
        i = j;
    }

    return stones_to_remove;
}
