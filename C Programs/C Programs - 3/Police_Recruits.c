#include <stdio.h>
#include <stdlib.h>

void read(short *, int);
int find_no_untreated_crimes(short *, int);

int main()
{
    int no_of_events, untreated_crimes;

    scanf("%u",&no_of_events);

    short *events = malloc(no_of_events*sizeof(short));

    read(events, no_of_events);
    untreated_crimes = find_no_untreated_crimes(events, no_of_events);
    printf("%u\n",untreated_crimes);

    free(events);
    return 0;
}

void read(short *events, int no_of_events)
{
    int i;

    for(i = 0; i < no_of_events; i++)
    {
        scanf("%hu",(events + i));
    }
}

int find_no_untreated_crimes(short *events, int no_of_events)
{
    int untreated_crimes = 0, i, available_police_officers = 0;

    for(i = 0; i < no_of_events; i++)
    {
        if(*(events + i) == -1)
        {
            if(available_police_officers > 0)
            {
                available_police_officers--;
            }
            else if(available_police_officers == 0)
            {
                untreated_crimes++;
            }
        }
        else//Officers are recruited
        {
            available_police_officers = available_police_officers + *(events + i);
        }
    }

    return untreated_crimes;
}
