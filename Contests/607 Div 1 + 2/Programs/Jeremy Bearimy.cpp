#include <iostream>
#include <vector>

using namespace std;

struct Edge
{
    int u, v;
    long long weight;
    
    Edge(){};
    
    Edge(int U, int V, long long W)
    {
        u = U; v = V;
        weight = W;
    }
};

vector <vector <int> > tree;
vector <int> subtree_size;
vector <int> parent;

void dfs(int v, int parent_v)
{
    parent[v] = parent_v;
    subtree_size[v] = 1;
    
    for(int i = 0; i < tree[v].size(); i++)
    {
        int child_v = tree[v][i];
        
        if(child_v == parent_v)
        {
            continue;
        }
        
        dfs(child_v, v);
        
        subtree_size[v] += subtree_size[child_v];
    }
}

void solve()
{
    int no_of_pairs;
    cin >> no_of_pairs;
    
    int no_of_vertices = 2*no_of_pairs;
    int no_of_edges = no_of_vertices - 1;
    
    vector <Edge> E(no_of_edges + 1);
    
    tree.resize(no_of_vertices + 1);
    subtree_size.resize(no_of_vertices + 1);
    parent.resize(no_of_vertices + 1);
    
    for(int i = 1; i <= no_of_vertices; i++)
    {
        tree[i].clear();
        
        subtree_size[i] = 0;
        
        parent[i] = 0;
    }
    
    for(int i = 1; i <= no_of_edges; i++)
    {
        cin >> E[i].u >> E[i].v >> E[i].weight;
        
        tree[E[i].u].push_back(E[i].v);
        tree[E[i].v].push_back(E[i].u);
    }
    
    dfs(1, 0);
    
    long long minimum = 0, maximum = 0;
    for(int i = 1; i <= no_of_edges; i++)
    {
        int u_subtree, v_subtree;
        
        if(parent[E[i].v] == E[i].u)
        {
            v_subtree  = subtree_size[E[i].v];
            u_subtree = no_of_vertices - v_subtree;
        }
        else
        {
            u_subtree = subtree_size[E[i].u];
            v_subtree = no_of_vertices - u_subtree;
        }
        
        int minimum_component = min(u_subtree, v_subtree);
        
        maximum += minimum_component*E[i].weight;
        minimum += (u_subtree%2 == 1 || v_subtree%2 == 1 ? E[i].weight : 0);
    }
    
    cout << minimum << " " << maximum << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
