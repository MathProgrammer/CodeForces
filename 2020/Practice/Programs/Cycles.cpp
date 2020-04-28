#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_N = 105;
int graph[MAX_N][MAX_N];

long long choose_3(long long n)
{
    return (n*(n - 1)*(n - 2))/6;
}

long long choose_2(long long n)
{
    return (n*(n - 1))/2;
}

void add_edge(int u, int v)
{
    graph[u][v] = 1;
    graph[v][u] = 1;
}

int main()
{
    int no_of_edges;
    cin >> no_of_edges;
    
    int complete_graph = 0;
    for(int i = 1; ; i++)
    {
        if(choose_3(i) > no_of_edges)
        {
            complete_graph = i - 1;
            no_of_edges -= choose_3(complete_graph);
            break;
        }
    }
    
    vector <int> extra_matching;
    while(no_of_edges > 0)
    {
        for(int i = complete_graph; i >= 0; i--)
        {
            if(choose_2(i) <= no_of_edges)
            {
                extra_matching.push_back(i);
                
                no_of_edges -= choose_2(i);
                
                break;
            }
        }
    }
    
    memset(graph, 0, sizeof(graph));
    
    for(int i = 1; i <= complete_graph; i++)
    {
        for(int j = i + 1; j <= complete_graph; j++)
        {
            add_edge(i, j);
        }
    }
    
    for(int i = 0; i < extra_matching.size(); i++)
    {
        int v = complete_graph + i + 1;
        int v_limit = extra_matching[i];
        
        for(int w = 1; w <= v_limit; w++)
        {
            add_edge(v, w);
        }
    }
    
    int no_of_vertices = complete_graph + extra_matching.size();
    
    cout << no_of_vertices << "\n";
    for(int i = 1; i <= no_of_vertices; i++)
    {
        for(int j = 1; j <= no_of_vertices; j++)
        {
            cout << graph[i][j];
        }
        
        cout << "\n";
    }
    
    return 0;
}
