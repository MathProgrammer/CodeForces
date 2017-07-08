#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

#define to_lower(ch) ( ch += (ch >= 'A' && ch <= 'Z' ?  'a' - 'A' : 0) )
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
        case 'y':
                    return true;
        default :
                    return false;
    }
}

int main()
{
    char initial_string[MAX_LENGTH];
    string answer;
    scanf("%s", initial_string);

    for(int i = 0; initial_string[i] != '\0'; i++)
    {
        if(is_vowel(to_lower(initial_string[i])) == false)
        {
            answer += '.';
            answer += to_lower(initial_string[i]);
        }
    }

    cout << answer << "\n";
    return 0;
}
