#include <cstdio>

int main()
{
    int no_of_numbers, k;
    scanf("%d %d", &no_of_numbers, &k);

    int good_numbers = 0;
    for(int i = 1; i <= no_of_numbers; i++)
    {
        int number, digit_present[10] = {false}, smallest_missing_digit = 0;
        scanf("%d", &number);

        if(number == 0)
            digit_present[0] = true;

        while(number > 0)
        {
            digit_present[number%10] = true;
            number = number/10;
        }

        while(digit_present[smallest_missing_digit] && smallest_missing_digit < 10)
            smallest_missing_digit++;

        good_numbers += (smallest_missing_digit > k);
    }

    printf("%d\n", good_numbers);
    return 0;
}
