#include <cstdio>

#define NO_OF_ALPHABETS 26
#define MAX_LENGTH 1000 + 5
#define max(a, b) (a > b ? a : b)

int main()
{
    char string[MAX_LENGTH];
    int min_distinct_characters;
    scanf("%s %d", string, &min_distinct_characters);

    int frequency[NO_OF_ALPHABETS] = {0};
    for(int i = 0; string[i] != '\0'; i++)
    {
        frequency[string[i] - 'a']++;
    }

    int no_of_distinct_characters = 0, no_of_changeable_characters = 0;
    for(int i = 0; i < NO_OF_ALPHABETS; i++)
    {
        if(frequency[i] > 0)
        {
            no_of_distinct_characters++;
            no_of_changeable_characters += (frequency[i] - 1); //Keep one character
        }
    }

    int minimum_changes = max(min_distinct_characters - no_of_distinct_characters, 0); //printf("NO of changes = %d\n", no_of_changeable_characters);

    printf(minimum_changes > no_of_changeable_characters ? "impossible\n" : "%d\n",minimum_changes);
    return 0;
}
