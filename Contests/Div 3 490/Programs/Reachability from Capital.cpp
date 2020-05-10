#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

const int MAX_N = 5015;
vector <int> graph[MAX_N];
vector <int> visited(MAX_N, false);
vector <int> visit_order;

vector <int> reverse_graph[MAX_N];
vector <int> component(MAX_N, 0);

vector <int> component_graph[MAX_N];
vector <int> reachable_component(MAX_N, false);

void dfs(int v)
{
    visited[v] = true;

    for(int i = 0; i < graph[v].size(); i++)
    {
        int child = graph[v][i];

        if(!visited[child])
            dfs(child);
    }
    
    visit_order.push_back(v);
}

void reverse_dfs(int v, int c)
{
    component[v] = c;
    
    for(int i = 0; i < reverse_graph[v].size(); i++)
    {
        int child = reverse_graph[v][i];
        
        if(component[child] == 0)
            reverse_dfs(child, c);
    }
}

void component_dfs(int v)
{
    reachable_component[v] = true;
    
    for(int i = 0; i < component_graph[v].size(); i++)
    {
        int child_v = component_graph[v][i];
        
        if(!reachable_component[child_v])
            dfs(child_v);
    }
}

int main()
{
    int no_of_vertices, no_of_edges, source;
    scanf("%d %d %d", &no_of_vertices, &no_of_edges, &source);

    for(int i = 1; i <= no_of_edges; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        graph[u].push_back(v);
        reverse_graph[v].push_back(u);
    }

    for(int i = 1; i <= no_of_vertices; i++)
    {
        if(!visited[i])
        {
            dfs(i);
        }
    }

    int no_of_components = 0;
    reverse(all(visit_order));
    for(int i = 0; i < no_of_vertices; i++)
    {
        int v = visit_order[i];
        if(component[v] == 0)
        {
            reverse_dfs(v, ++no_of_components);
        }
    }
    
    vector <int> incoming(no_of_components + 1);
    
    for(int v = 1; v <= no_of_vertices; v++)
    {
        for(int i = 0; i < graph[v].size(); i++)
        {
            int child = graph[v][i];
            
            if(component[v] != component[child])
            {
                component_graph[component[v]].push_back(component[child]);
                incoming[component[child]]++;
            }
        }
    }
    
    component_dfs(component[source]);
    
    int new_edges = 0;
    for(int i = 1; i <= no_of_components; i++)
    {
        if(!reachable_component[i] && incoming[i] == 0)
        {
            new_edges++;
        }
    }
    
    printf("%d\n", new_edges);

    return 0;
}
