#include <stdio.h>
#include <stdlib.h>

void read(unsigned long *, unsigned long *, unsigned int);
unsigned long get_maximum(unsigned long *, unsigned long *, unsigned int);

int main()
{
    unsigned int no_of_numbers;
    unsigned long maximum;

    scanf("%u",&no_of_numbers);

    unsigned long *list_1 = malloc(no_of_numbers*sizeof(unsigned long));
    unsigned long *list_2 = malloc(no_of_numbers*sizeof(unsigned long));

    read(list_1, list_2, no_of_numbers);
    maximum = get_maximum(list_1, list_2, no_of_numbers);

    printf("%lu\n",maximum);

    free(list_1);
    free(list_2);
    return 0;
}

void read(unsigned long *list_1, unsigned long *list_2, unsigned int no_of_numbers)
{
    unsigned int i;

    for(i = 0; i < no_of_numbers; i++)
    {
        scanf("%lu",(list_1 + i));
    }

    for(i = 0; i < no_of_numbers; i++)
    {
        scanf("%lu",(list_2 + i));
    }
}

unsigned long get_maximum(unsigned long *list_1, unsigned long *list_2, unsigned int no_of_numbers)
{
    unsigned int i;
    unsigned long function_list_1 = *list_1, function_list_2 = *list_2;

    //Finding f(a, 1, n) and f(b, 1, n) i.e. - the bitwise OR of the entire array
    for(i = 1; i < no_of_numbers; i++)
    {
        function_list_1 = function_list_1 | *(list_1 + i);
        function_list_2 = function_list_2 | *(list_2 + i);
    }
    return (function_list_1 + function_list_2);
}
