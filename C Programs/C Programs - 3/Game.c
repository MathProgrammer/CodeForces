#include <stdio.h>

int main()
{
    short no_of_balls_in_box_1, no_of_balls_in_box_2;
    short max_balls_1_can_throw, max_balls_2_can_throw;

    scanf("%hu %hu %hu %hu",&no_of_balls_in_box_1, &no_of_balls_in_box_2, &max_balls_1_can_throw,&max_balls_2_can_throw);

    if(no_of_balls_in_box_1 > no_of_balls_in_box_2)
    {
        printf("First\n");
    }
    else //In case of equality, the second player wins
    {
        printf("Second\n");
    }
    return 0;
}
