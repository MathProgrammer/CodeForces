#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector <int> P(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> P[i];
    }

    vector <int> visited(no_of_elements + 1, false);
    vector <int> cycle_length(no_of_elements + 1, 0);

    for(int i = 1; i <= no_of_elements; i++)
    {
        if(visited[i])
        {
            continue;
        }

        vector <int> cycle;
        int v = i;

        while(!visited[v])
        {
            visited[v] = true;

            cycle.push_back(v);

            v = P[v];
        }

        for(int g = 0; g < cycle.size(); g++)
        {
            int v = cycle[g];

            cycle_length[v] = cycle.size();
        }
    }

    for(int i = 1; i <= no_of_elements; i++)
    {
        cout << cycle_length[i] << " ";
    }

    cout << "\n";
}

int main()
{
    int no_of_queries;
    cin >> no_of_queries;

    while(no_of_queries--)
        solve();

    return 0;
}

