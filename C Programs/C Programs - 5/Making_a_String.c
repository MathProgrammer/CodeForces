#include <stdio.h>
#include <stdlib.h>

void read(long long*, short);
void selection_sort_descending(long long*, short);
long long min(long long, long long);
long long find_longest_string(long long*, short);

int main()
{
    short no_of_letters;

    scanf("%hu",&no_of_letters);

    long long longest_length, *occurence_of_letter = malloc(no_of_letters*sizeof(long long));

    read(occurence_of_letter, no_of_letters);
    selection_sort_descending(occurence_of_letter, no_of_letters);
    longest_length = find_longest_string(occurence_of_letter, no_of_letters);

    printf("%I64d\n",longest_length);
    free(occurence_of_letter);
    return 0;
}

long long find_longest_string(long long*occurence_of_letter, short no_of_letters)
{
    short i;
    long long longest_length = 0, maximum_frequency_current = *(occurence_of_letter + 0);

    for(i = 0; (i < no_of_letters) && (maximum_frequency_current > 0); i++)
    {
        longest_length += min(maximum_frequency_current, *(occurence_of_letter + i));
        maximum_frequency_current = min(maximum_frequency_current, *(occurence_of_letter + i));
        maximum_frequency_current--;
    }

    return longest_length;
}

long long min(long long a, long long b)
{
    if(a < b)
        return a;
    else
        return b;
}

void read(long long*occurence_of_letter, short no_of_letters)
{
    short i;

    for(i = 0; i < no_of_letters; i++)
    {
        scanf("%I64d",(occurence_of_letter + i));
    }
}

void selection_sort_descending(long long*occurence_of_letter, short no_of_letters)
{
    short i, j, largest_index;
    long long largest;

    //Every iteration finds the i-th maxima. So, for n elements, we only need to sort n-1 elements. The last element is forced to be in it's correct position.
    for(i = 0; i < no_of_letters - 1; i++)
    {
        largest = *(occurence_of_letter + i);
        largest_index = i;

        for(j = i + 1; j  < no_of_letters; j++)//Go through the list from i to the end to search for a maxima
        {
            if(*(occurence_of_letter + j) > largest)
            {
                largest = *(occurence_of_letter + j);
                largest_index = j;
            }
        }

        //Place the i-th minima in the i-th position, and the element at the i-th position where the maxima was
        *(occurence_of_letter + largest_index) = *(occurence_of_letter + i);
        *(occurence_of_letter + i) = largest;
    }
}
