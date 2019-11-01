#include <iostream>

using namespace std;

int main()
{
    long long no_of_games, points, win_point, draw_point;
    cin >> no_of_games >> points >> win_point >> draw_point;

    int limit = win_point - 1;
    for(int draws = 0; points >= draws*draw_point && draws <= limit; draws++)
    {
        if( (points - draws*draw_point)%win_point == 0)
        {
            long long wins = (points - draws*draw_point)/win_point;

            long long losses = no_of_games - wins - draws;

            if(losses >= 0)
            {
                cout << wins << " " << draws << " " << losses;

                return 0;
            }
        }
    }
    cout << "-1\n";
    return 0;
}
