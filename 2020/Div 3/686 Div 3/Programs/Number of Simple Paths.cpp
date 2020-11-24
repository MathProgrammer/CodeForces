#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 5e5 + 5;
int no_of_vertices;
vector <int> graph[MAX_N];
vector <int> parent(MAX_N, 0);
vector <int> visited(MAX_N, false);
vector <int> lies_on_cycle(MAX_N, false);
vector <int> cycle;

void dfs(int v, int parent_v)
{
    if(visited[v] == 2)
    {
        return ;
    }
    
    if(visited[v] == 1)
    {
        lies_on_cycle[v] = true;
        cycle.push_back(v);
        
        int u = parent_v;
        
        while(u != v)
        {
            cycle.push_back(u);
            
            lies_on_cycle[u] = true;
            u = parent[u];
            
            visited[u] = 2;
        }
        
        return;
    }
    
    visited[v] = 1;
    parent[v] = parent_v;
    
    for(int i = 0; i < graph[v].size(); i++)
    {
        int child_v = graph[v][i];
        
        if(child_v == parent_v)
        {
            continue;
        }
        
        dfs(child_v, v);
    }
    
    visited[v] = 2;
}

int dfs_without_cycle(int v, int parent_v)
{
    int count = 1;
    
    for(int i = 0; i < graph[v].size(); i++)
    {
        int child_v = graph[v][i];
        
        if(child_v == parent_v || lies_on_cycle[child_v])
        {
            continue;
        }
        
        count += dfs_without_cycle(child_v, v);
    }
    
    return count;
}

long long choose_2(long long n)
{
    return (n*(n - 1))/2;
}

void solve()
{
    cin >> no_of_vertices;
    
    cycle.clear();
    
    for(int i = 1; i <= no_of_vertices; i++)
    {
        graph[i].clear();
        
        parent[i] = 0;
        visited[i] = false;
        lies_on_cycle[i] = false;
    }
    
    for(int i = 1; i <= no_of_vertices; i++)
    {
        int u, v;
        cin >> u >> v;
        
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    long long remaining = 0;
    long long answer = 0;
    
    dfs(1, 0);
    
    for(int i = 0; i < cycle.size(); i++)
    {
        int v = cycle[i];
        
        long long subtree_here = dfs_without_cycle(v, 0);
        
        long long inside = choose_2(subtree_here);
        long long inside_outside = 2*(subtree_here*remaining);
        //cout << "Multiplying 2 " << inside << " " << remaining << " = " << inside_outside << "\n";
        
        answer += (inside + inside_outside);
        
        remaining += subtree_here;
    }
    
    cout << answer << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
