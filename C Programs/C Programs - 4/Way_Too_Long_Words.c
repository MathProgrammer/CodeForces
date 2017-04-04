#include <stdio.h>
#include <string.h>

int main()
{
    short no_of_words, i;
    char current_word[101];
    scanf("%hu",&no_of_words);
    for(i = 0; i < no_of_words; i++)
    {
        scanf("%s",current_word);
        if(strlen(current_word) > 10)
        {
            printf("%c%d%c\n",current_word[0],strlen(current_word)-2, current_word[strlen(current_word)-1]);
        }
        else
        {
            printf("%s\n",current_word);
        }
    }
    return 0;
}
