#include <cstdio>
#include <cstring>

#define MAX_LENGTH 100 + 5
#define to_upper(ch) (ch >= 'a' && ch <= 'z' ?  ch - ('a' - 'A') : ch)
#define is_alpha(ch) (to_upper(ch) >= 'A' && to_upper(ch) <= 'Z' ? true : false)

bool is_vowel(char ch)
{
    switch(to_upper(ch))
    {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        case 'Y': return true;
    }
    return false;
}

int main()
{
    char question[MAX_LENGTH];
    fgets(question, MAX_LENGTH, stdin);

    bool last_letter_vowel = false;
    for(int i = strlen(question) - 1; i >= 0; i--)
    {
        if(is_alpha(question[i]) )
        {
            if(is_vowel(question[i]) )
               last_letter_vowel = true;

            break;
        }
    }

    printf(last_letter_vowel ? "YES\n" : "NO\n");
    return 0;
}
