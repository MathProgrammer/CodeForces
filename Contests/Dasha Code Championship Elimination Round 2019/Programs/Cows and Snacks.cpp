#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 5;
vector <int> graph[MAX_N];
vector <int> visited(MAX_N, false);

int dfs_component_size(int v)
{
    if(visited[v])
        return 0;

    int component_size = 1;

    visited[v] = true;

    for(int i = 0; i < graph[v].size(); i++)
    {
        int child = graph[v][i];

        if(visited[child])
        {
            continue;
        }

        component_size += dfs_component_size(child);
    }

    return component_size;
}

int main()
{
    int no_of_snacks, no_of_animals;
    cin >> no_of_snacks >> no_of_animals;

    for(int i = 1; i <= no_of_animals; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int happy_animals = 0;
    for(int i = 1; i <= no_of_snacks; i++)
    {
        if(!visited[i])
        {
            int component_size = dfs_component_size(i);

            happy_animals += (component_size - 1);
        }
    }

    int unhappy_animals = no_of_animals - happy_animals;

    cout << unhappy_animals;
    return 0;
}
