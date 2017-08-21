#include <cstdio>
#include <map>

#define NO_OF_ALPHABETS 26
#define MAX_LENGTH 1000 + 2
#define tolower(ch) (ch >= 'A' && ch <= 'Z' ? ch + 'a' - 'A' : ch)
#define tocapital(ch) (ch >= 'a' && ch <= 'z' ? ch - ('a' - 'A') : ch)
#define isalpha(ch) (tolower(ch) >= 'a' && tolower(ch) <= 'z' ? true : false)
#define is_capital(ch) (ch >= 'A' && ch <= 'Z' ? true : false)

using namespace std;

int main()
{
    char keyboard_1[NO_OF_ALPHABETS], keyboard_2[NO_OF_ALPHABETS];
    scanf("%s %s", keyboard_1, keyboard_2);

    map <char, char> corresponding_keyboard_2_char;
    for(int i = 0; i < NO_OF_ALPHABETS; i++)
    {
        corresponding_keyboard_2_char[ keyboard_1[i] ] = keyboard_2[i];
    }

    char text[MAX_LENGTH];
    scanf("%s", text);

    for(int i = 0; text[i] != '\0'; i++)
    {
        if(isalpha(text[i]))
        {
            char input = tolower(text[i]);
            putchar(is_capital(text[i]) ? tocapital(corresponding_keyboard_2_char[input]) : corresponding_keyboard_2_char[input]);
        }
        else
        {
            putchar(text[i]); //Not there in the keyboards
        }
    }
    return 0;
}
