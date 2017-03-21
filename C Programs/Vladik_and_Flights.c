#include <stdio.h>
#include <stdlib.h>

int main()
{
    short cost;
    unsigned long no_of_airports, start_airport, destination_airport;
    scanf("%lu %lu %lu",&no_of_airports, &start_airport, &destination_airport);

    char *company_of_airport = malloc((no_of_airports+1)*sizeof(char)); //Allocating an extra character

    scanf("%s",company_of_airport);

    //If the airports are of the same company, cost is 0. Else it is 1.
    if( *(company_of_airport + start_airport - 1) == *(company_of_airport + destination_airport- 1) )//1 is subtracted because counting starts from 0 in the array
    {
        cost = 0;
    }
    else
    {
        cost = 1;
    }

    printf("%hu\n",cost);
    free(company_of_airport);
    return 0;
}
