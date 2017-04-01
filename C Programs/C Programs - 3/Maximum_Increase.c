#include <stdio.h>
#include <stdlib.h>

void read(unsigned long *, unsigned int);
unsigned int find_length_max_increasing_subsequence(unsigned long *, unsigned int);

int main()
{
    unsigned int no_of_numbers, maximum_subsequence_length;
    scanf("%u",&no_of_numbers);

    unsigned long *number_sequence = malloc(no_of_numbers*sizeof(unsigned long));
    read(number_sequence, no_of_numbers);

    maximum_subsequence_length = find_length_max_increasing_subsequence(number_sequence, no_of_numbers);
    printf("%u\n",maximum_subsequence_length);

    free(number_sequence);
    return 0;
}

void read(unsigned long *number_sequence, unsigned int no_of_numbers)
{
    unsigned int i;

    for(i = 0 ; i < no_of_numbers; i++)
    {
        scanf("%lu",(number_sequence + i));
    }
}

unsigned int find_length_max_increasing_subsequence(unsigned long *number_sequence, unsigned int no_of_numbers)
{
    unsigned int i, j, length_of_increasing_subsequence = 0, maximum_increasing_subsequence = 1;

    for(i = 0; i < no_of_numbers; )
    {
        length_of_increasing_subsequence = 1;

        //Finds the length of the increasing subsequence starting at i
        for(j = i + 1; (*(number_sequence + j) > *(number_sequence + j - 1) ) && (j < no_of_numbers); j++)
        {
            length_of_increasing_subsequence++;
        }
        i = j; //i resumes where j ends i.e. It starts from the next subsequence/**< /**< /**< /**< /**<  */ */ */ */ */

        if(length_of_increasing_subsequence > maximum_increasing_subsequence)
        {
            maximum_increasing_subsequence = length_of_increasing_subsequence;
        }
    }

    return maximum_increasing_subsequence;
}
