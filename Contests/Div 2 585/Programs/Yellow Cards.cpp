#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int team_1, yellow_1, team_2, yellow_2, yellow;
    cin >> team_1 >> team_2 >> yellow_1 >> yellow_2 >> yellow;

    int total_people = team_1 + team_2;
    int max_cards_without_elimination = team_1*(yellow_1 - 1) + team_2*(yellow_2 - 1);

    int minimum_eliminations, maximum_eliminations;

    if(max_cards_without_elimination >= yellow)
    {
        minimum_eliminations = 0;
    }
    else
    {
        minimum_eliminations = min(total_people, (yellow - max_cards_without_elimination));
    }


    if(yellow_2 < yellow_1)
    {
        swap(yellow_1, yellow_2);

        swap(team_1, team_2);
    }

    maximum_eliminations = min(team_1, yellow/yellow_1);

    yellow -= maximum_eliminations*yellow_1;

    maximum_eliminations += min(team_2, yellow/yellow_2);

    cout << minimum_eliminations << " " << maximum_eliminations << "\n";
    return 0;
}
