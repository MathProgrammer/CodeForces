#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

const int MAX_N = 2e5 + 15;
int visited[MAX_N];
set <int> complement_graph[MAX_N], unvisited;

int dfs_component_size(int v)
{
    unvisited.erase(v);

    int size_here = 1;

    for(set <int> :: iterator it = unvisited.begin(); it != unvisited.end(); )
    {   
        if(complement_graph[v].count(*it) == 0)
        {
            int child = *it;

            size_here += dfs_component_size(child);

            it = unvisited.lower_bound(child);
        }
        else
        {
            it++;
        }
    }

    return size_here;
}

int main()
{
    int no_of_vertices, no_of_edges;
    scanf("%d %d", &no_of_vertices, &no_of_edges);

    for(int i = 1; i <= no_of_vertices; i++)
        unvisited.insert(i);

    for(int i = 1; i <= no_of_edges; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        complement_graph[u].insert(v);
        complement_graph[v].insert(u);
    }

    int no_of_components = 0;
    vector <int> component_size;

    for(int i = 1; i <= no_of_vertices; i++)
    {
        if(unvisited.count(i) == 1)
        {
            no_of_components++;

            component_size.push_back(dfs_component_size(i));
        }
    }

    sort(all(component_size));

    printf("%d\n", no_of_components);
    for(int i = 0; i < no_of_components; i++)
        printf("%d ", component_size[i]);

    return 0;
}
