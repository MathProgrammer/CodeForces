#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 5, WHITE = 1, BLACK = 0;
vector <int> tree[MAX_N];
int colour[MAX_N], sum_from[MAX_N];

void dfs(int v, int parent_v)
{
    sum_from[v] = (colour[v] == WHITE ? 1 : -1);
    
    for(int i = 0; i < tree[v].size(); i++)
    {
        int child_v = tree[v][i];
        
        if(child_v == parent_v)
        {
            continue;
        }
        
        dfs(child_v, v);
        
        sum_from[v] += max(sum_from[child_v], 0);
    }
}

void dfs_adjust(int v, int parent_v)
{
    for(int i = 0; i < tree[v].size(); i++)
    {
        int child_v = tree[v][i];
        
        if(child_v == parent_v)
        {
            continue;
        }
        
        int parent_sum = sum_from[v];
        
        if(sum_from[child_v] > 0)
        {
            parent_sum -= sum_from[child_v];
        }
        
        if(parent_sum > 0)
        {
            sum_from[child_v] += parent_sum;
        }
        
        dfs_adjust(child_v, v);
    }
}

int main()
{
    int no_of_vertices;
    cin >> no_of_vertices;
    
    for(int i = 1; i <= no_of_vertices; i++)
    {
        cin >> colour[i];
    }
    
    int no_of_edges = no_of_vertices - 1;
    for(int i = 1; i <= no_of_edges; i++)
    {
        int u, v;
        cin >> u >> v;
        
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    dfs(1, 0);
    dfs_adjust(1, 0);
    
    for(int i = 1; i <= no_of_vertices; i++)
    {
        cout << sum_from[i] << " ";
    }
    
    cout << "\n";
    
    return 0;
}
