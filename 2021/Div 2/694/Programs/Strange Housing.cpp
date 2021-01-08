#include <iostream>
#include <vector>
#include <map>
#include  <algorithm>
#include <queue>

using namespace std;

void solve()
{
    int no_of_vertices, no_of_edges;
    cin >> no_of_vertices >> no_of_edges;

    vector <vector <int> > graph(no_of_vertices + 1);
    for(int i = 1; i <= no_of_edges; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    const int UNCOLOURED = -1, BLACK = 0, WHITE = 1;
    vector <int> colour(no_of_vertices + 1, UNCOLOURED);
    queue <int> Q;
    colour[1] = WHITE;
    for(int child : graph[1])
    {
        colour[child] = BLACK;

        Q.push(child);
    }

    while(!Q.empty())
    {
        int v = Q.front(); Q.pop();

        for(int child : graph[v])
        {
            if(colour[child] == UNCOLOURED)
            {
                colour[child] = WHITE;

                for(int grandchild : graph[child])
                {
                    colour[grandchild] = BLACK;

                    Q.push(grandchild);
                }
            }
        }
    }

    vector <int> answer;
    for(int i = 1; i  <= no_of_vertices; i++)
    {
        if(colour[i] == WHITE)
        {
            answer.push_back(i);
        }

        if(colour[i] == UNCOLOURED)
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    cout << answer.size() << "\n";
    for(int v :  answer)
    {
        cout << v << " ";
    }

    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
