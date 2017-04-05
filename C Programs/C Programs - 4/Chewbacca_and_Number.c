#include <stdio.h>
#define NO_OF_DIGITS 20

void transform_n_to_minimum(char[]);
int main()
{
    char number[NO_OF_DIGITS];
    scanf("%s",number);
    transform_n_to_minimum(number);
    printf("%s",number);
    return 0;
}

void transform_n_to_minimum(char number[])
{
    short i;

    for(i = 0; number[i] != '\0'; i++)
    {
        //Digits greater than 5 are replaced by their compliment
        if(('5' <= number[i]) && (number[i] <= '9'))
        {
            number[i] = '9' - number[i] + '0';
        }
    }

    if(number[0] == '0')//If first digit is zero, then it means it was a 9. We leave it untouched.
    {
        number[0] = '9';
    }
}
