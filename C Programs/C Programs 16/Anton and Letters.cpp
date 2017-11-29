#include <iostream>
#include <string>
#include <set>

#define is_alpha(x) ('a' <= x && x <= 'z')
using namespace std;

int main()
{
    string line;
    getline(cin, line);

    set <char> letters;
    for(int i = 0; i < line.size(); i++)
    {
        if(is_alpha(line[i]))
            letters.insert(line[i]);
    }

    cout << letters.size();

    return 0;
}
