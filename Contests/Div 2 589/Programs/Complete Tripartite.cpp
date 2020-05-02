#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int no_of_vertices, no_of_edges;
    cin >> no_of_vertices >> no_of_edges;
    
    set <int> graph[no_of_vertices + 1];
    for(int i = 1; i <= no_of_edges; i++)
    {
        int u, v;
        cin >> u >> v;
        
        graph[u].insert(v);
        graph[v].insert(u);
    }
    
    const int NO_OF_GROUPS = 3;
    vector <int> group(no_of_vertices + 1, 0);
    vector <int> group_sizes(NO_OF_GROUPS + 1, 0);
    for(int g = 1; g <= NO_OF_GROUPS; g++)
    {
        int first = 0;
        
        for(first = 1; first <= no_of_vertices && group[first] != 0; first++);
        
        if(first == no_of_vertices + 1)
        {
            cout << "-1\n";
            
            return 0;
        }
        
        group[first] = g;
        for(int second = 1; second <= no_of_vertices; second++)
        {
            if(graph[first].find(second) == graph[first].end())
            {
                group[second] = g;
                group_sizes[g]++;
            }
        }
    }
    
    for(int v = 1; v <= no_of_vertices; v++)
    {
        if(group[v] == 0)
        {
            cout << "-1\n";
            
            return 0;
        }
    }
    
    for(int v = 1; v <= no_of_vertices; v++)
    {
        for(auto it = graph[v].begin(); it != graph[v].end(); it++)
        {
            int u = *it;
            
            if(group[u] == group[v])
            {
                cout << "-1\n";
                
                return 0;
            }
        }
    }
    
    for(int v = 1; v <= no_of_vertices; v++)
    {
        int other_groups = group_sizes[1] + group_sizes[2] + group_sizes[3]
                            - group_sizes[group[v]];
        
        if(graph[v].size() != other_groups)
        {
            cout << "-1\n";
            
            return 0;
        }
    }
    
    for(int v = 1; v <= no_of_vertices; v++)
    {
        cout << group[v] << " ";
    }
    
    cout << "\n";
    return 0;
}
