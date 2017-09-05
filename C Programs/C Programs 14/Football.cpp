#include <string>
#include <iostream>
#include <map>

using namespace std;

int main()
{
    int no_of_lines;
    cin >> no_of_lines;

    map <string, int> no_of_goals;

    while(no_of_lines--)
    {
        string team;
        cin >> team;

        no_of_goals[team]++;
    }

    string winner;
    int max_goals = 0;
    for(map <string, int> :: iterator i = no_of_goals.begin(); i != no_of_goals.end(); i++)
    {
        int no_of_goals = i->second;
        if(no_of_goals > max_goals)
        {
            max_goals = no_of_goals;
            winner = i->first;
        }
    }

    cout << winner;
    return 0;
}
