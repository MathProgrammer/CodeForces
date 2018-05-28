#include <cstdio>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 15;
vector <int> graph[MAX_N];

int dfs_leaf_from(int v, int parent)
{
    if(graph[v].size() == 1)
        return v;

    for(int i = 0; i < graph[v].size(); i++)
    {
        int child = graph[v][i];

        if(child == parent) continue;

        return dfs_leaf_from(child, v);
    }
}

int main()
{
    int no_of_vertices;
    scanf("%d", &no_of_vertices);

    for(int i = 1; i < no_of_vertices; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int no_of_roots = 0, root = 1;
    for(int i = 1; i <= no_of_vertices; i++)
    {
        if(graph[i].size() > 2)
        {
            no_of_roots++;
            root = i;
        }
    }

    if(no_of_roots > 1)
    {
        printf("No\n");
        return 0;
    }

    printf("Yes\n");

    int no_of_paths = graph[root].size();

    printf("%d\n", no_of_paths);

    for(int i = 0; i < graph[root].size(); i++)
    {
        int child = graph[root][i];

        int leaf = dfs_leaf_from(child, root);

        printf("%d %d\n", root, leaf);
    }

    return 0;
}
