#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define all(v) (v).begin(), (v).end()

const int MAX_N = 3e5 + 5;
vector <int> tree[MAX_N];
vector <int> depth(MAX_N, 0);
vector <int> subtree_from(MAX_N, 0);

void dfs(int v, int parent_v)
{
    if(depth[v] != 0)
    {
        return;
    }
    
    depth[v] = 1 + depth[parent_v];
    
    for(int i = 0; i < tree[v].size(); i++)
    {
        int child_v = tree[v][i];
        
        if(child_v == parent_v)
        {
            continue;
        }
        
        dfs(child_v, v);
        
        subtree_from[v] += (1 + subtree_from[child_v]);
    }
}

int main()
{
    int no_of_vertices, chosen_vertices;
    cin >> no_of_vertices >> chosen_vertices;
    
    int no_of_edges = no_of_vertices - 1;
    for(int i = 1; i <= no_of_edges; i++)
    {
        int u, v;
        cin >> u >> v;
        
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    depth[0] = -1;
    dfs(1, 0);
    
    vector <long long> contribution;
    for(int v = 1; v <= no_of_vertices; v++)
    {
        contribution.push_back(depth[v] - subtree_from[v]);
    }
    
    sort(all(contribution));
    reverse(all(contribution));
    
    long long sum = 0;
    for(int i = 0; i < chosen_vertices; i++)
    {
        sum += contribution[i];
    }
    
    cout << sum << "\n";
    return 0;
}
