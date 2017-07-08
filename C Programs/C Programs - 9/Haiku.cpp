#include <cstdio>

#define MAX_LENGTH 100 + 2

bool is_vowel(char ch)
{
    switch(ch)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
                    return true;
        default :
                    return false;
    }
}

int main()
{
    bool is_haiku = true;
    char line[MAX_LENGTH];
    const int no_of_lines = 3;

    for(int i = 1; i <= no_of_lines; i++)
    {
        int vowel_count = 0;

        fgets(line, MAX_LENGTH, stdin);

        for(int letter = 0; line[letter] != '\n'; letter++)
            vowel_count += is_vowel(line[letter]);

        if(i == 2)
        {
            if(vowel_count != 7)
                is_haiku = false;
        }
        else
        {
            if(vowel_count != 5)
                is_haiku = false;
        }
    }

    printf(is_haiku ? "YES\n" : "NO\n");
    return 0;
}
