#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 5, MAX_L = 25;
vector <int> tree[MAX_N];
int parent[MAX_N][MAX_L], depth[MAX_N];

int is_bit_set(long long n, int bit)
{
    return ( (n&(1LL << bit)) != 0);
}

void dfs(int v, int parent_v)
{
    parent[v][0] = parent_v;
    
    depth[v] = depth[parent_v] + 1;
    
    for(int i = 0; i < tree[v].size(); i++)
    {
        int child_v = tree[v][i];
        
        if(child_v == parent_v)
        {
            continue;
        }
        
        dfs(child_v, v);
    }
}

void precompute_parents(int no_of_vertices)
{
    for(int l = 1; l < MAX_L; l++)
    {
        for(int v = 1; v <= no_of_vertices; v++)
        {
            int ancestor = parent[v][l - 1];
            
            parent[v][l] = parent[ancestor][l - 1];
        }
    }
}

int LCA(int u, int v)
{
    if(depth[v] < depth[u])
    {
        swap(u, v);
    }
    
    int difference = depth[v] - depth[u];
    
    for(int i = MAX_L - 1; i >= 0; i--)
    {
        if(is_bit_set(difference, i))
        {
            v = parent[v][i];
        }
    }
    
    if(u == v)
    {
        return v;
    }
    
    for(int i = MAX_L - 1; i >= 0; i--)
    {
        if(parent[v][i] != parent[u][i])
        {
            v = parent[v][i];
            u = parent[u][i];
        }
    }
    
    return parent[v][0];
}

int distance(int u, int v)
{
    int l = LCA(u, v);
    
    if(l == u)
    {
        return (depth[v] - depth[l]);
    }
    
    if(l == v)
    {
        return (depth[u] - depth[l]);
    }
    
    return (depth[v] - depth[l]) + (depth[u] - depth[l]);
}

int main()
{
    int no_of_vertices;
    cin >> no_of_vertices;
    
    int no_of_edges = no_of_vertices - 1;
    for(int i = 1; i <= no_of_edges; i++)
    {
        int u, v;
        cin >> u >> v;
        
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    depth[0] = 0;
    
    dfs(1, 0);
    
    precompute_parents(no_of_vertices);
    
    int no_of_queries;
    cin >> no_of_queries;
    
    for(int i = 1; i <= no_of_queries; i++)
    {
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        
        int path_1 = distance(a, b);
        int path_2 = distance(a, x) + distance(b, y) + 1;
        int path_3 = distance(a, y) + distance(b, x) + 1;
        
        if( (path_1 <= k && path_1%2 == k%2) ||
            (path_2 <= k && path_2%2 == k%2) ||
            (path_3 <= k && path_3%2 == k%2) )
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    
    return 0;
}
