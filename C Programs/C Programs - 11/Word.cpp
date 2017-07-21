#include <cstdio>

#define is_capital(ch) (ch >= 'A' && ch <= 'Z' ? true : false)
#define lower_case(ch) (is_capital(ch) ? ch + 'a' - 'A' : ch)
#define capital(ch) (is_capital(ch) ? ch : ch - ('a' - 'A') )
#define MAX_LENGTH 100 + 2

int main()
{
    char word[MAX_LENGTH];
    scanf("%s", word);

    int i, no_of_capitals = 0, no_of_lower_case = 0, length;
    for(i = 0; word[i] != '\0'; i++)
    {
        no_of_capitals += is_capital(word[i]) ;
    }
    length = i;
    no_of_lower_case = (length - no_of_capitals);

    if(no_of_lower_case >= no_of_capitals)
    {
        for(i = 0; word[i] != '\0'; i++)
        {
            putchar(lower_case(word[i]));
        }
    }
    else
    {
        for(int i = 0; i < length; i++)
        {
            putchar(capital(word[i]));
        }
    }

    return 0;
}
