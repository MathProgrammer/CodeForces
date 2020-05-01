#include <iostream>
#include <vector>

using namespace std;

vector <int> parent, time_in, time_out, depth;
vector <vector <int> > tree;

void dfs(int v, int parent_v, int &time)
{
    time_in[v] = time++;
    
    parent[v] = parent_v;
    depth[v] = depth[parent_v] + 1;
    
    for(int i = 0; i < tree[v].size(); i++)
    {
        int child_v = tree[v][i];
        
        if(child_v == parent_v)
        {
            continue;
        }
        
        dfs(child_v, v, time);
    }
    
    time_out[v] = time++;
}

void solve()
{
    int no_of_query_vertices;
    cin >> no_of_query_vertices;
    
    vector <int> v(no_of_query_vertices + 1);
    for(int i = 1; i <= no_of_query_vertices; i++)
    {
        cin >> v[i];
    }
    
    int max_depth = 0;
    int last_v = 0;
    for(int i = 1; i <= no_of_query_vertices; i++)
    {
        if(depth[v[i]] > max_depth)
        {
            max_depth = depth[v[i]];
            last_v = v[i];
        }
    }
    
    for(int i = 1; i <= no_of_query_vertices; i++)
    {
        if(v[i] == last_v || v[i] == 1)
        {
            continue;
        }
        
        v[i] = parent[v[i]];
    }
    
    int lies_on_one_path = true;
    for(int i = 1; i <= no_of_query_vertices; i++)
    {
        //cout << "V = " << v[i] << " Time In = " << time_in[v[i]] << " Time Out = " << time_out[v[i]] << "\n";
        if(time_in[v[i]] > time_out[last_v] || time_out[v[i]] < time_in[last_v])
        {
            lies_on_one_path = false;
        }
    }
    
    cout << (lies_on_one_path ? "YES\n" : "NO\n");
}

int main()
{
    int no_of_vertices, no_of_queries;
    cin >> no_of_vertices >> no_of_queries;
    
    tree.resize(no_of_vertices + 1);
    int no_of_edges = no_of_vertices - 1;
    for(int i = 1; i <= no_of_edges; i++)
    {
        int u, v;
        cin >> u >> v;
        
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    parent.resize(no_of_vertices + 1);
    depth.resize(no_of_vertices + 1);
    time_in.resize(no_of_vertices + 1);
    time_out.resize(no_of_vertices + 1);
    
    int time = 0;
    dfs(1, 0, time);
    
    /*for(int v = 1; v <= no_of_vertices; v++)
    {
        cout << "V = " << v << " Time in = " << time_in[v] << " Time out = " << time_out[v] << "\n";
    }*/
    
    for(int i = 1; i <= no_of_queries; i++)
    {
        solve();
    }
    
    return 0;
}
