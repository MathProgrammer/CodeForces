#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100002

int main()
{
    char string[MAX_LENGTH], reverse[MAX_LENGTH];
    int length, i;
    scanf("%s",string);

    length = strlen(string);
    for(i = 0; i < length; i++)
    {
        reverse[i] = string[length - i - 1];
    }
    reverse[length] = '\0';

    printf("%s%s\n",string,reverse);
    return 0;
}

