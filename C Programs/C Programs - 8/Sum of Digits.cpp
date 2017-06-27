#include <stdio.h>

#define MAX_LENGTH 100000 + 1

int find_digit_sum(int n)
{
    int sum = 0;

    while(n > 0)
    {
        sum += n%10;
        n /= 10;
    }
    return sum;
}

int main()
{
    char number[MAX_LENGTH];
    int i, digit_sum = 0, no_of_spells = 0;
    scanf("%s", number);

    if(number[1] != '\0')
    {
        for(i = 0; number[i] != '\0'; i++)
            digit_sum += (number[i] - '0');

        no_of_spells = 1;
        while(digit_sum >= 10)
        {
            no_of_spells++;
            digit_sum = find_digit_sum(digit_sum);
        }
    }

    printf("%d\n", no_of_spells);
    return 0;
}
