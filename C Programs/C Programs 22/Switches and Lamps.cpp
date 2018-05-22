#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_switches, no_of_lamps;
    cin >> no_of_switches >> no_of_lamps;

    vector <string> switches(no_of_switches);
    for(int i = 0; i < no_of_switches; i++)
        cin >> switches[i];

    vector <int> no_of_switches_for(no_of_lamps, 0);
    for(int i = 0; i < no_of_switches; i++)
        for(int lamp = 0; lamp < no_of_lamps; lamp++)
            no_of_switches_for[lamp] += (switches[i][lamp] == '1');

    int one_ignorable = false;

    for(int i = 0; i < no_of_switches; i++)
    {
        int can_ignore_this_one = true;

        for(int lamp = 0; lamp < no_of_lamps; lamp++)
        {
            if(switches[i][lamp] == '1' && no_of_switches_for[lamp] == 1)
                can_ignore_this_one = false;
        }

        if(can_ignore_this_one)
            one_ignorable = true;
    }

    cout << (one_ignorable ? "YES\n" : "NO\n");

    return 0;
}

