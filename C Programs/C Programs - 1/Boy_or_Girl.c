#include <stdio.h>
#include <string.h>

#define MAXIMUM_DISTINCT_LETTERS 27 //26 + 1
#define USERNAME_SIZE_LIMIT 101
#define ADVICE_SIZE_LIMIT 14 //13+1
#define true 1
#define false 0

void prepare_advisory_message(char[], short);
short check_if_username_is_female(char[]);

int main()
{
    char message_of_advice[ADVICE_SIZE_LIMIT], username[USERNAME_SIZE_LIMIT];
    short is_a_girl;

    scanf("%s",username);

    is_a_girl = check_if_username_is_female(username);
    prepare_advisory_message(message_of_advice, is_a_girl);
    printf("%s\n",message_of_advice);
    return 0;
}

short check_if_username_is_female(char username[])
{
    char distinct_letters[MAXIMUM_DISTINCT_LETTERS], current_char;
    short i, j, distinct_count = 0, already_counted;

    for(i = 0; username[i] != '\0';i++)
    {
        current_char = username[i];
        already_counted = false;
        for(j = 0; j < distinct_count; j++)
        {
            if(current_char == distinct_letters[j])
            {
                already_counted = true;
            }
        }

        if(already_counted == false)
        {
            distinct_letters[distinct_count++] = current_char;
        }
    }
    if(distinct_count %2 == 0)
    {
        return true; //It is a girl
    }
    else
    {
        return false; //It is a boy
    }
}
void prepare_advisory_message(char message_of_advice[], short is_a_girl)
{
    if(is_a_girl == true)
    {
        strcpy(message_of_advice, "CHAT WITH HER!");
    }
    else
    {
        strcpy(message_of_advice, "IGNORE HIM!");
    }
}
