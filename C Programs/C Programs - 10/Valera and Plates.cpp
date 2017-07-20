#include <cstdio>

int main()
{
    int no_of_days, no_of_bowls, no_of_plates;
    scanf("%d %d %d", &no_of_days, &no_of_bowls, &no_of_plates);

    int no_of_cleanings = 0;
    for(int i = 1; i <= no_of_days; i++)
    {
        int dish_type;
        scanf("%d", &dish_type);

        if(dish_type == 1)
        {
            if(no_of_bowls == 0)
                no_of_cleanings++;
            else
                no_of_bowls--;
        }

        if(dish_type == 2)
        {
            if(no_of_plates == 0 && no_of_bowls == 0)
                no_of_cleanings++;
            else if(no_of_plates > 0)
                no_of_plates--;
            else
                no_of_bowls--;
        }
    }

    printf("%d\n", no_of_cleanings);
    return 0;
}
