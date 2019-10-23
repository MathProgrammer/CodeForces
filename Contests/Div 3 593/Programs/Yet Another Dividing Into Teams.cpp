#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int no_of_people;
    cin >> no_of_people;

    const int MAX = 105;
    vector <int> present(MAX + 1, false);
    for(int i = 1; i <= no_of_people; i++)
    {
        int skill;
        cin >> skill;

        present[skill] = true;
    }

    int no_of_teams = 1;
    for(int i = 1; i < MAX; i++)
    {
        if(present[i] && present[i + 1])
        {
            no_of_teams = 2;

            break;
        }
    }

    cout << no_of_teams << "\n";
}

int main()
{
    int no_of_queries;
    cin >> no_of_queries;

    while(no_of_queries--)
        solve();

    return 0;
}
