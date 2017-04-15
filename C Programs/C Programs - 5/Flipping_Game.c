#include <stdio.h>
#include <stdlib.h>

void read(short *, short);
short find_maximum_number_of_ones_after_move(short *, short);
short greatest_continuous_sum(short *, short);
int max(int, int);

int main()
{
    short no_of_numbers, maximum_number_of_ones;

    scanf("%hu",&no_of_numbers);

    short *gain = malloc(no_of_numbers*sizeof(short));

    read(gain, no_of_numbers);
    maximum_number_of_ones = find_maximum_number_of_ones_after_move(gain, no_of_numbers);

    printf("%hu\n",maximum_number_of_ones);

    free(gain);
    return 0;
}

void read(short *gain, short no_of_numbers)
{
    short i, current;

    for(i = 0; i < no_of_numbers; i++)
    {
        scanf("%hu",&current);
        /*If there is a 0, the number of 1s increases by 1 after flipping. If it is a 1, the number of 1s increases by -1 after flipping
        G[i] = -1, if A[i] = 1 and
        G[i] = 0, if A[i] = 0*/
        *(gain + i) = ( (current == 0) ? 1 : -1 );
    }
}

short find_maximum_number_of_ones_after_move(short *gain, short no_of_numbers)
{
    short i, number_of_1s_before_move = 0, number_of_1s_after_move;

    //This is the number of 1s in the original array. Corresponds to G[i] = -1
    for(i = 0; i < no_of_numbers; i++)
    {
        if(*(gain + i) == -1)
        {
            number_of_1s_before_move++;
        }
    }

    number_of_1s_after_move = greatest_continuous_sum(gain, no_of_numbers);

    return (number_of_1s_before_move + number_of_1s_after_move);
}

short greatest_continuous_sum(short *gain, short no_of_numbers)
{
    short i, greatest_sum = *(gain + 0), current_sum = *(gain + 0);

    for(i = 1; i < no_of_numbers; i++)
    {
        current_sum = max(current_sum + *(gain + i), *(gain + i));
        greatest_sum = max(greatest_sum, current_sum);
    }

    return greatest_sum;
}

int max(int a, int b)
{
    return (a > b ? a: b);
}
