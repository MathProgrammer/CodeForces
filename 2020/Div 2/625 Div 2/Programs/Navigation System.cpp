#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 2e5 + 5;
vector <int> graph[MAX_N];
vector <int> transpose_graph[MAX_N];
vector <int> D(MAX_N, -1);

void bfs(int source)
{
    queue <int> Q;
    
    Q.push(source);
    D[source] = 0;
    
    while(!Q.empty())
    {
        int v = Q.front();
        Q.pop();
        
        for(int i = 0; i < transpose_graph[v].size(); i++)
        {
            int child = transpose_graph[v][i];
            
            if(D[child] == -1)
            {
                D[child] = D[v] + 1;
                
                Q.push(child);
            }
        }
    }
}

int main()
{
    int no_of_vertices, no_of_edges;
    cin >> no_of_vertices >> no_of_edges;
    
    for(int i = 1; i <= no_of_edges; i++)
    {
        int u, v;
        cin >> u >> v;
        
        graph[u].push_back(v);
        transpose_graph[v].push_back(u);
    }
    
    int no_of_stops;
    cin >> no_of_stops;
    
    vector <int> stops(no_of_stops + 1, 0);
    for(int i = 1; i <= no_of_stops; i++)
    {
        cin >> stops[i];
    }
    
    int source = stops[no_of_stops];
    bfs(source);
    
    int minimum_paths = 0, maximum_paths = 0;
    for(int i = 1; i < no_of_stops; i++)
    {
        if(D[stops[i + 1]] + 1 != D[stops[i]])
        {
            minimum_paths++;
            maximum_paths++;
            continue;
        }
        
        int no_of_options = 0;
        for(int j = 0; j < graph[stops[i]].size(); j++)
        {
            int next = graph[stops[i]][j];
            
            if(D[next] + 1 == D[stops[i]])
            {
                no_of_options++;
            }
        }
        
        if(no_of_options > 1)
        {
            maximum_paths++;
        }
    }
    
    cout << minimum_paths << " " << maximum_paths << "\n";
    return 0;
}
