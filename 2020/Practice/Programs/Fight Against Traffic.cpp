#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

const int MAX_N = 1005;
vector <int> graph[MAX_N];
set <int> edge_exists[MAX_N];

void bfs(int source, vector <int> &distance)
{
    queue <int> Q;
    
    Q.push(source);
    distance[source] = 0;
    
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        
        for(int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i];
            
            if(distance[v] == -1)
            {
                distance[v] = distance[u] + 1;
                
                Q.push(v);
            }
        }
    }
}

int main()
{
    int no_of_vertices, no_of_edges;
    cin >> no_of_vertices >> no_of_edges;
    
    int source, target;
    cin >> source >> target;
    
    for(int i = 1; i <= no_of_edges; i++)
    {
        int u, v;
        cin >> u >> v;
        
        graph[u].push_back(v);
        graph[v].push_back(u);
        
        edge_exists[u].insert(v);
        edge_exists[v].insert(u);
    }
    
    vector <int> source_distance(no_of_vertices + 1, -1), target_distance(no_of_vertices + 1, -1);
    bfs(source, source_distance);
    bfs(target, target_distance);
    
    int minimum_distance = source_distance[target];
    long long no_of_good_pairs = 0;
    for(int u = 1; u <= no_of_vertices; u++)
    {
        for(int v = u + 1; v <= no_of_vertices; v++)
        {
            if(edge_exists[u].count(v) == 1)
            {
                continue;
            }
            
            if(source_distance[u] + 1 + target_distance[v] >= minimum_distance &&
               source_distance[v] + 1 + target_distance[u] >= minimum_distance)
            {   
                no_of_good_pairs++;
            }
        }
    }
    
    cout << no_of_good_pairs << "\n";
    
    return 0;
}
