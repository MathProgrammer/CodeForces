#include <cstdio>

#define MAX_SIZE 100000 + 2

int main()
{
    char number[MAX_SIZE];
    scanf("%s", number);

    char new_number[MAX_SIZE];
    int first_zero = -1, new_number_i = 0;

    for(int i = 0; number[i] != '\0'; i++)
    {
        if(number[i] == '0' && first_zero == -1)//Delete leftmost 0.
        {
            first_zero = i;
        }
        else
        {
            new_number[new_number_i++] = number[i];
        }
    }

    int last_digit_position = new_number_i;
    if(first_zero == -1) //If no 0, delete any 1.
        last_digit_position--;

    new_number[last_digit_position] = '\0';

    printf("%s\n", new_number);
    return 0;
}
