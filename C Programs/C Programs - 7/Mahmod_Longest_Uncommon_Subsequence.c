#include <stdio.h>
#include <string.h>

#define max(a, b) (a > b  ? a : b)
#define MAX_LENGTH 100000
int main()
{
    char string_1[MAX_LENGTH + 1], string_2[MAX_LENGTH + 1];
    scanf("%s %s",string_1, string_2);

    printf("%d\n", (strcmp(string_1, string_2) != 0 ? max( strlen(string_1),strlen(string_2) ) : -1) );
    return 0;
}
