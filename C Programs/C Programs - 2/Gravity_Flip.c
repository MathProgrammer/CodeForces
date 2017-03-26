#include <stdio.h>
#include <stdlib.h>

void read(short *, short);
void selection_sort(short *, short);
void display(short *, short);

int main()
{
    short no_of_columns;

    scanf("%hu",&no_of_columns);

    short *blocks = malloc(no_of_columns*sizeof(short));

    read(blocks, no_of_columns);
    selection_sort(blocks, no_of_columns);
    display(blocks, no_of_columns);

    free(blocks);
    return 0;
}

void read(short *blocks, short no_of_columns)
{
    short i;

    for(i = 0; i < no_of_columns; i++)
    {
        scanf("%hu",(blocks + i));
    }
}

void display(short *blocks, short no_of_columns)
{
    short i;

    for(i = 0; i < no_of_columns; i++)
    {
        printf("%hu\t",*(blocks + i));
    }
}

void selection_sort(short *blocks, short no_of_columns)
{
    short i, j, smallest, smallest_index;

    //Every iteration finds the i-th minima. So, for n elements, we only need to sort n-1 elements. The last element is forced to be in it's correct position.
    for(i = 0; i < no_of_columns - 1; i++)
    {
        smallest = *(blocks + i);
        smallest_index = i;

        for(j = i + 1; j  < no_of_columns; j++)//Go through the list from i to the end to search for a minima
        {
            if(*(blocks + j) < smallest)
            {
                smallest = *(blocks + j);
                smallest_index = j;
            }
        }

        //Place the i-th minima in the i-th position, and the element at the i-th position where the minima was
        *(blocks + smallest_index) = *(blocks + i);
        *(blocks + i) = smallest;
    }
}
