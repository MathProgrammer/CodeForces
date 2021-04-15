#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
const int MAX_N = 5e5 + 5;

set <int> unvisited;
vector <int> graph[MAX_N];
vector <vector <int> > components;

void dfs(int v)
{
    unvisited.erase(v);
    //C.push_back(v);
    components.back().push_back(v);

    for(auto it = unvisited.begin(); it != unvisited.end(); )
    {
        if(binary_search(graph[v].begin(), graph[v].end(), (*it)))
        {
            it++;
        }
        else
        {
            int child = *it;

            dfs(child);

            it = unvisited.lower_bound(child);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int no_of_vertices, no_of_edges;
    cin >> no_of_vertices >> no_of_edges;

    for(int i = 1; i <= no_of_edges; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i = 1; i <= no_of_vertices; i++)
    {
        unvisited.insert(i);

        sort(graph[i].begin(), graph[i].end());
    }

    while(unvisited.size() > 0)
    {
        int v = *(unvisited.begin());

        vector <int> C;
        components.push_back(C);
        dfs(v);
    }

    cout << components.size() << "\n";
    for(int c = 0; c < components.size(); c++)
    {
        cout << components[c].size() << " ";
        for(int v : components[c])
        {
            cout << v << " ";
        }

        cout << "\n";
    }

    return 0;
}
