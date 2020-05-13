#include <cstdio>
#include <vector>

using namespace std;

const int MAX_N = 1e5 + 15;
vector <int> graph[MAX_N];
vector <int> visited(MAX_N, false);
vector <int> incoming(MAX_N, 0);

vector <int> beginning;
vector <int> ending;

void dfs(int v)
{
    visited[v] = true;

    for(int i = 0; i < graph[v].size(); i++)
    {
        int child = graph[v][i];

        if(visited[child])
        {
            ending.push_back(child);

            return;
        }

        dfs(child);
    }
}

int main()
{
    int no_of_vertices;
    scanf("%d", &no_of_vertices);

    for(int i = 1; i <= no_of_vertices; i++)
    {
        int destination;
        scanf("%d", &destination);

        graph[i].push_back(destination);
        incoming[destination]++;
    }

    for(int i = 1; i <= no_of_vertices; i++)
    {
        if(incoming[i] == 0)
        {
            beginning.push_back(i);

            dfs(i);
        }
    }
    
    for(int i = 1; i <= no_of_vertices; i++)
    {
        if(!visited[i])
        {
            beginning.push_back(i);
            
            dfs(i);
        }
    }

    int no_of_sinks = 0;
    for(int i = 1; i <= no_of_vertices; i++)
    {
        if(incoming[i] == 0)
        {
            no_of_sinks++;
        }
    }
    
    int simple_cycle = (no_of_sinks == 0 && beginning.size() == 1);
    
    int new_edges = (simple_cycle ? 0 : beginning.size());
    printf("%d\n", new_edges);

    for(int i = 0; i < new_edges; i++)
    {
        printf("%d %d \n",ending[i], beginning[(i + 1)%new_edges]);
    }

    return 0;
}
