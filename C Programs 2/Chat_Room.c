#include <stdio.h>

#define true 1
#define false 0
#define MAX_MESSAGE_LENGTH 101

short is_hello_there(char[]);
int main()
{
    short if_hello_found;
    char message[MAX_MESSAGE_LENGTH];

    scanf("%s",message);

    if_hello_found = is_hello_there(message);
    if(if_hello_found)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}

short is_hello_there(char message[])
{
    char string_to_search[5] = "hello";
    short string_to_search_index = 0, i, hello_found = false;

    for(i = 0; message[i] != '\0'; i++)
    {
        if(string_to_search[string_to_search_index] == message[i])
        {
            string_to_search_index++;
            if(string_to_search_index == 5)
            {
                hello_found = true;
                return hello_found;
            }
        }
    }
    return hello_found;
}
