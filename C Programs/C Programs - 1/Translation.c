#include <stdio.h>
#include <string.h>

#define true 1
#define false 0
#define ANSWER_SIZE 4 //Yes or No
#define WORD_SIZE_LIMIT 102

int main()
{
    char word[WORD_SIZE_LIMIT], reversed_word[WORD_SIZE_LIMIT], answer[ANSWER_SIZE];
    short correct_translation = true, i, length;

    scanf("%s %s",word, reversed_word);
    length = strlen(word);

    if(strlen(word) != strlen(reversed_word))
    {
        correct_translation = false;
    }

    for(i = 0; i < length; i++)
    {
        if(word[i] != reversed_word[length - i - 1])
        {
            correct_translation = false;
            break;
        }
    }

    if(correct_translation)
    {
        strcpy(answer, "YES");
    }
    else
    {
        strcpy(answer, "NO");
    }

    printf("%s\n",answer);
    return 0;
}
