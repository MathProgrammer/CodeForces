#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int other(int p)
{
    return (p + 1)%2;
}

void dfs(vector < vector <int> > &T, int parent_v, int v, map <pair <int, int>, int> &weight, int parity)
{
    for(int child_v : T[v])
    {
        if(child_v == parent_v)
        {
            continue;
        }

        int x = v, y = child_v;
        if(x > y)
        {
            swap(x, y);
        }

        weight[make_pair(x, y)] = (parity == 0 ? 2 : 3);

        dfs(T, v, child_v, weight, other(parity));
    }
}

void solve()
{
    int no_of_vertices;
    cin >> no_of_vertices;

    int no_of_edges = no_of_vertices - 1;
    vector <pair <int, int> > edges;
    vector <vector <int> > tree(no_of_vertices + 1);
    for(int i = 1; i <= no_of_edges; i++)
    {
        int u, v;
        cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);

        if(u > v)
        {
            swap(u, v);
        }

        edges.push_back(make_pair(u, v));
    }

    int possible = true;
    int root = 1;
    for(int i = 1; i <= no_of_vertices; i++)
    {
        if(tree[i].size() >= 3)
        {
            possible = false;
            break;
        }

        if(tree[i].size() == 1)
        {
            root = i;
        }
    }

    if(!possible)
    {
        cout << "-1\n";
        return;
    }

    map <pair <int, int>, int > edge_weight;
    dfs(tree, 0, root, edge_weight, 0);

    for(pair <int, int> edge : edges)
    {
        cout << edge_weight[edge] << " ";
    }
    cout << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}


