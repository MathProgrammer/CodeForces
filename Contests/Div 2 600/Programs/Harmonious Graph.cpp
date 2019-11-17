#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

const int MAX_N = 2e5 + 5, oo = 1e9;
vector <int> graph[MAX_N];
vector <int> visited(MAX_N, false);

struct component
{
    int minimum, maximum;

    component()
    {
        minimum = oo, maximum = 0;
    };

    component(int Min, int Max)
    {
        minimum = Min, maximum = Max;
    }
};

void dfs(int v, component &C)
{
    if(visited[v])
    {
        return;
    }

    visited[v] = true;

    C.minimum = min(C.minimum, v);
    C.maximum = max(C.maximum, v);

    for(int i = 0; i < graph[v].size(); i++)
    {
        int child = graph[v][i];

        dfs(child, C);
    }
}

int main()
{
    int no_of_vertices, no_of_edges;
    cin >> no_of_vertices >> no_of_edges;

    for(int i = 1; i <= no_of_edges; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector <component> components;
    for(int i = 1; i <= no_of_vertices; i++)
    {
        if(!visited[i])
        {
            component this_component;

            dfs(i, this_component);

            components.push_back(this_component);
        }
    }

    //Components are already sorted by their Lefts

    int right_most_point = 0;
    int no_of_connections = 0;
    for(int i = 0; i < components.size(); i++)
    {
        if(components[i].minimum < right_most_point)
        {
            no_of_connections++;
        }

        right_most_point = max(right_most_point, components[i].maximum);
    }

    cout << no_of_connections << "\n";
    return 0;
}
