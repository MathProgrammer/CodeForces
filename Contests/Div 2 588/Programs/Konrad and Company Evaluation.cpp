#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAX_N = 1e5 + 5;
vector <long long> indegree(MAX_N, 0), outdegree(MAX_N, 0);
vector <int> graph[MAX_N], transpose_graph[MAX_N];

long long contribution(int v)
{
    return indegree[v]*outdegree[v];
}

int main()
{
    int no_of_vertices, no_of_edges;
    cin >> no_of_vertices >> no_of_edges;
    
    for(int i = 1; i <= no_of_edges; i++)
    {
        int u, v;
        cin >> u >> v;
        
        if(u > v)
        {
            swap(u, v);
        }
        
        graph[u].push_back(v);
        
        //Reverse
        indegree[v]++;
        outdegree[u]++;
    }
    
    int no_of_queries;
    cin >> no_of_queries;
    
    long long no_of_paths = 0;
    for(int i = 1; i <= no_of_vertices; i++)
    {
        no_of_paths += contribution(i);
    }
    
    cout << no_of_paths << "\n";
    for(int i = 1; i <= no_of_queries; i++)
    {
        int v;
        cin >> v;
        
        no_of_paths -= contribution(v);
        
        for(auto child_v : graph[v])
        {   //cout << "u = " << u << "\n";
            no_of_paths -= contribution(child_v); //cout << "Old Contribution = " << contribution(u) << "\n";
            
            indegree[child_v]--;
            outdegree[v]--;
            
            graph[child_v].push_back(v);
            indegree[v]++;
            outdegree[child_v]++;
            
            no_of_paths += contribution(child_v); //cout << "New Contribution = " << contribution(u) << "\n";
        }
        
        graph[v].clear();
        
        no_of_paths += contribution(v);
        
        cout << no_of_paths << "\n";
    }
    
    return 0;
}
