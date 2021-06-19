#include <iostream>
#include <vector>

using namespace std;

const int UNCOLOURED = -1, RED = 0, BLUE = 1;

int other(int colour)
{
    return (1 - colour);
}

int dfs_bipartite_check(vector <vector <int> > &graph, int v, vector <int> &C, int colour)
{
    C[v] = colour; //cout << "Colour " << v << " = " << C[v] << "\n";

    for(int child_v : graph[v])
    {
        if(C[child_v] == C[v])
        {   //cout << v << " and " << child_v << " have the same colour\n";
            return false;
        }

        if(C[child_v] == UNCOLOURED)
        {
            if(!dfs_bipartite_check(graph, child_v, C, other(colour)))
            {
                return false;
            }
        }
    }

    return true;
}

void solve()
{
    int no_of_vertices, no_of_edges;
    cin >> no_of_vertices >> no_of_edges;

    vector <int> value(no_of_vertices + 1);
    for(int i = 1; i <= no_of_vertices; i++)
    {
        cin >> value[i];
    }

    vector <int> target(no_of_vertices + 1);
    for(int i = 1; i <= no_of_vertices; i++)
    {
        cin >> target[i];
    }

    vector <vector <int> > graph(no_of_vertices + 1);
    for(int i = 1; i <= no_of_edges; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector <int> colour(no_of_vertices + 1, UNCOLOURED);
    int is_bipartite = dfs_bipartite_check(graph, 1, colour, RED);

    long long red_remaining = 0, blue_remaining = 0, total_remaining = 0;
    for(int i = 1; i <= no_of_vertices; i++)
    {
        switch(colour[i])
        {
            case RED : red_remaining += (target[i] - value[i]); break;
            case BLUE : blue_remaining += (target[i] - value[i]); break;
        }

        total_remaining += (target[i] - value[i]);
    }

    int possible; //cout << "Bipartite = " << is_bipartite << "\n";

    if(is_bipartite)
    {
        possible = (red_remaining == blue_remaining);
    }
    else
    {
        possible = (total_remaining%2 == 0);
    }

    cout << (possible ? "YES" : "NO") << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
