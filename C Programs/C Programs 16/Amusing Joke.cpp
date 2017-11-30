#include <cstdio>

int main()
{
    const int NO_OF_ALPHABETS = 26;
    int frequency[NO_OF_ALPHABETS] = {0};

    for(int i = 1; i <= 3; i++)
    {
        const int MAX_LENGTH = 103;
        char name[MAX_LENGTH];
        scanf("%s", name);

        for(int j = 0; name[j] != '\0'; j++)
            frequency[name[j] - 'A'] += (i == 3 ? -1 : 1);
    }

    int is_possible = true;
    for(int i = 0; i < NO_OF_ALPHABETS; i++)
        if(frequency[i] != 0)
            is_possible = false;

    printf(is_possible ? "YES\n" : "NO\n");
    return 0;
}
