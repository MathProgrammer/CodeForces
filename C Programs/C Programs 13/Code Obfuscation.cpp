#include <cstdio>
#include <set>

#define MAX_LENGTH 500 + 2
using namespace std;

int main()
{
    char code[MAX_LENGTH];
    scanf("%s", code);

    set <char> alphabets_used;
    int code_obfuscation = true;

    for(int i = 0; code[i] != '\0'; i++)
    {
        //Before inserting an alphabet, all alphabets smaller than it must already have been used
        if(alphabets_used.count(code[i]) == 0)
        {
            if(alphabets_used.size() < code[i] - 'a')
            {
                code_obfuscation = false;
                break;
            }
        }
        alphabets_used.insert(code[i]);
    }


    printf(code_obfuscation ? "YES\n" : "NO\n");
    return 0;
}
