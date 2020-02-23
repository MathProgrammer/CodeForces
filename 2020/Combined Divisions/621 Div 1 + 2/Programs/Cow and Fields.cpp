#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_N = 5e5 + 5, oo = 1e9 + 9;
vector <int> graph[MAX_N];

void bfs(int source, vector <int> &distance)
{
    queue <int> Q;
    
    Q.push(source);
    distance[source] = 0;
    
    while(!Q.empty())
    {
        int v = Q.front();
        Q.pop();
        
        for(int i = 0; i < graph[v].size(); i++)
        {
            int child = graph[v][i];
            
            if(distance[child] >= oo)
            {
                distance[child] = distance[v] + 1;
                
                Q.push(child);
                
                //cout << "Child = " << child << " Distance = " << distance[child] << "\n";
            }
        }
    }
}

int main()
{
    int no_of_vertices, no_of_edges, no_of_special_vertices;
    cin >> no_of_vertices >> no_of_edges >> no_of_special_vertices;
    
    vector <int> special_vertices(no_of_special_vertices);
    for(int i = 0; i < no_of_special_vertices; i++)
    {
        cin >> special_vertices[i];
    }
    
    for(int i = 1; i <= no_of_edges; i++)
    {
        int u, v;
        cin >> u >> v;
        
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    vector <int> distance_1(no_of_vertices + 1, oo);
    bfs(1, distance_1);
    
    vector <int> distance_n(no_of_vertices + 1, oo);
    bfs(no_of_vertices, distance_n);
    
    sort(special_vertices.begin(), special_vertices.end(), [&] (int a, int b)
    {
        return (distance_1[a] - distance_n[a] < distance_1[b] - distance_n[b]);
    });
    
    int maximum_distance = 0;
    int furthest_1 = distance_1[special_vertices[0]];
    
    for(int i = 1; i < no_of_special_vertices; i++)
    {
        maximum_distance = max(maximum_distance,
                               furthest_1 + distance_n[special_vertices[i]] + 1);
        
        //cout << special_vertices[i] << "\n";
        //cout << "Distance n = " << distance_n[special_vertices[i]] << " Furthest 1 = " << furthest_1 << "\n";
        //cout << "Maximum Distance = " << maximum_distance << "\n";
        furthest_1 = max(furthest_1, distance_1[special_vertices[i]]);
    }
    
    maximum_distance = min(maximum_distance, distance_n[1]);
    
    cout << maximum_distance << "\n";
    return 0;
}
