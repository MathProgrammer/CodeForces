#include <stdio.h>
#include <string.h>

#define true 1
#define false 0

short check_if_nearly_lucky(char[]);
int main()
{
    char number[19];
    short is_nearly_lucky;

    scanf("%s",number);

    is_nearly_lucky = check_if_nearly_lucky(number);

    if(is_nearly_lucky == true)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}

short check_if_nearly_lucky(char number[])
{
    short i, count_of_lucky_digits = 0;

    for(i = 0; number[i] != '\0'; i++)
    {
        if( (number[i] == '4') || (number[i] == '7') )
        {
            count_of_lucky_digits++;
        }
    }

    if( (count_of_lucky_digits == 4) || (count_of_lucky_digits == 7) )//Less than 18 digits are there so these are the only possibilities
    {

        return true;
    }
    return false;
}
