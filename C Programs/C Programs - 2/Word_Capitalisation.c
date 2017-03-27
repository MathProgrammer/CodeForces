#include <stdio.h>
#include <stdlib.h>
#define MAX_WORD_SIZE 1001
int main()
{
    char *word = malloc(MAX_WORD_SIZE*sizeof(char));
    scanf("%s",word);

    if( ('a' <= *(word + 0) ) && ('z' >= *(word + 0)) )
    {
        *(word + 0) = *(word + 0) - ('a' - 'A'); //The ASCII capitals come before the smaller letters. Subtracting the first letter to make it small
    }

    printf("%s\n",word);
    free(word);
    return 0;
}
