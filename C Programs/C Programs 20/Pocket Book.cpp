#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    int no_of_names, length;
    cin >> no_of_names >> length;

    set <int> distinct_characters[length];

    while(no_of_names--)
    {
        string name;
        cin >> name;

        for(int i = 0; i < length; i++)
            distinct_characters[i].insert(name[i]);
    }

    const int MOD = 1e9 + 7;
    long long total_strings = 1;

    for(int i = 0; i < length; i++)
    {
        total_strings = (total_strings*distinct_characters[i].size())%MOD;
    }

    cout << total_strings;
    return 0;
}
