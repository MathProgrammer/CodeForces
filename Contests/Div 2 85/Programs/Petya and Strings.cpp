#include <cstdio>
#include <string.h>

#define MAX_LENGTH 100 + 1
#define tolower(c) (c < 'a' ? (c + 'a' - 'A') : c)

int main()
{
    char string_1[MAX_LENGTH], string_2[MAX_LENGTH];
    scanf("%s %s", string_1, string_2);

    for(int i = 0; string_1[i] != '\0'; i++)
    {
        if(tolower(string_1[i]) > tolower(string_2[i]) )
        {
            printf("1\n");
            return 0;
        }
        else if(tolower(string_1[i]) < tolower(string_2[i]) )
        {
            printf("-1\n");
            return 0;
        }
    }

    printf("0\n");
    return 0;
}
