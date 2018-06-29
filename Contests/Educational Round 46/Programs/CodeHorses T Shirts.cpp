#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    int no_of_shirts;
    cin >> no_of_shirts;

    map <string, int> size_frequency;
    for(int i = 1; i <= no_of_shirts; i++)
    {
        string shirt_size;
        cin >> shirt_size;

        size_frequency[shirt_size]++;
    }

    int no_of_changes = 0;
    for(int i = 1; i <= no_of_shirts; i++)
    {
        string shirt_size;
        cin >> shirt_size;

        if(size_frequency[shirt_size] > 0)
            size_frequency[shirt_size]--;
        else
            no_of_changes++;
    }

    cout << no_of_changes;
    return 0;
}
