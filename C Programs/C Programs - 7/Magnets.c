#include <stdio.h>

int main()
{
    int no_of_magnets, i, no_of_magnet_groups = 0;
    char previous_orientation = 'X', current_orientation, current_magnet[3];
    scanf("%d", &no_of_magnets);

    for(i = 1; i <= no_of_magnets; previous_orientation = current_orientation, i++)
    {
        scanf("%s",current_magnet);
        current_orientation = current_magnet[0];

        if(previous_orientation != current_orientation)
            no_of_magnet_groups++;
    }

    printf("%d\n",no_of_magnet_groups);
    return 0;
}
