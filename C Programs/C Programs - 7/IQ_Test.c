#include <stdio.h>

int main()
{
    int no_of_numbers, number, no_of_even_numbers = 0, no_of_odd_numbers = 0, last_even_index, last_odd_index, i;
    scanf("%d", &no_of_numbers);

    for(i = 1; i <= no_of_numbers; i++)
    {
        scanf("%d", &number);

        if(number%2 == 0)
            no_of_even_numbers++, last_even_index = i;
        else
            no_of_odd_numbers++, last_odd_index = i;
    }

    printf("%d\n", (no_of_even_numbers == 1 ? last_even_index : last_odd_index) );
    return 0;
}
