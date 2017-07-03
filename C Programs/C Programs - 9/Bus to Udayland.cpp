#include <cstdio>

#define ROW_LENGTH 5 + 1
#define MAX_ROWS 1000 + 1

int main()
{
    char bus_seating[MAX_ROWS][ROW_LENGTH];
    int no_of_rows;
    scanf("%d", &no_of_rows);

    bool can_sit_together = false;

    for(int i = 0; i < no_of_rows; i++)
    {
        scanf("%s", bus_seating[i]);

        if(bus_seating[i][0] == 'O' && bus_seating[i][1] == 'O' && can_sit_together == false)
        {
            bus_seating[i][0] = bus_seating[i][1] = '+';
            can_sit_together = true;
        }

        if(bus_seating[i][3] == 'O' && bus_seating[i][4] == 'O' && can_sit_together == false)
        {
            bus_seating[i][3] = bus_seating[i][4] = '+';
            can_sit_together = true;
        }
    }

    if(can_sit_together)
    {
        printf("YES\n");
        for(int i = 0; i < no_of_rows; i++)
            printf("%s\n",bus_seating[i]);
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}
