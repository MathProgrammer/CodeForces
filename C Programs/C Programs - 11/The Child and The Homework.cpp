#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define MAX_LENGTH 100 + 2

int main()
{
    typedef pair <int, char> int_char;

    char option[MAX_LENGTH];
    vector <int_char> option_length;

    for(int i = 0; i < 4; i++)
    {
        scanf("%s", option);
        option_length.push_back(make_pair(strlen(option) - 2, 'A' + i)); //Excluding the alphabet and the .
    }

    sort(all(option_length));

    char answer = 'C';
    if(2*option_length[0].first <= option_length[1].first && option_length[3].first >= 2*option_length[2].first)//Two options
    {
        answer = 'C';
    }
    else if(2*option_length[0].first <= option_length[1].first)
    {
        answer = option_length[0].second;
    }
    else if(option_length[3].first >= 2*option_length[2].first)
    {
        answer = option_length[3].second;
    }

    printf("%c\n", answer);
    return 0;
}
