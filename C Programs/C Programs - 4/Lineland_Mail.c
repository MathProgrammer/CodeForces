#include <stdio.h>
#include <stdlib.h>

void read(long *, unsigned int);
void get_minimum(long *, long *, unsigned int);
long min(long a, long b);
long max(long a, long b);
void get_maximum(long *, long *, unsigned int);
void display(long *, long *, unsigned int);

int main()
{
    unsigned int no_of_cities;

    scanf("%u",&no_of_cities);

    long *city = malloc(no_of_cities*sizeof(long));
    long *minimum = malloc(no_of_cities*sizeof(long));
    long *maximum = malloc(no_of_cities*sizeof(long));

    read(city, no_of_cities);
    get_minimum(minimum, city, no_of_cities);
    get_maximum(maximum, city, no_of_cities);
    display(minimum, maximum, no_of_cities);

    free(city);
    free(minimum);
    free(maximum);
    return 0;
}

void read(long *city, unsigned int no_of_cities)
{
    unsigned int i;

    for(i = 0; i < no_of_cities; i++)
    {
        scanf("%ld",(city + i));
    }
}

void display(long *minimum, long *maximum, unsigned int no_of_cities)
{
    unsigned int i;

    for(i = 0; i < no_of_cities; i++)
    {
        printf("%ld\t%ld\n",*(minimum + i), *(maximum + i));
    }
}

void get_minimum(long *minimum, long *city, unsigned int no_of_cities)
{
    unsigned int i;
    //The minimum distance is one of the adjacent cities. The first and last city have only one adjacent city so we solve it separately.
    *(minimum + 0) = *(city + 1) - *(city + 0); //For First city, it has to be the next city
    *(minimum + no_of_cities - 1) = *(city + no_of_cities - 1)-*(city + no_of_cities - 2); //For last city, it has to be the previous city

    for(i = 1; i < no_of_cities - 1; i++)
    {
        *(minimum + i) = min( abs(*(city + i) - *(city + i -1)), abs(*(city + i) - *(city + i +1))); //The closer distance among the next and previous city
    }
}

long min(long a, long b)
{
    if(a < b)
        return a;
    else
        return b;
}

long max(long a, long b)
{
    if(a > b)
        return a;
    else
        return b;
}

void get_maximum(long *maximum, long *city, unsigned int no_of_cities)
{
    unsigned int i;

    //The cities are given in ascending order. Clearly, the city at the maximum distance is either the first city or the last city.
    //max{A[i], A[n] - A[i]} is the maximum cost from the i-th city
    for(i = 0; i < no_of_cities; i++)
    {
        *(maximum + i) = max(*(city + i) - *(city + 0), *(city + no_of_cities - 1) - *(city + i));
    }
}
