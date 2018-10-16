#include <cstdio>
#include <vector>

using namespace std;

const int MAX_N = 105;
vector <int> visited(MAX_N, false);
vector <int> graph[MAX_N];

void dfs(int v)
{
    visited[v] = true;

    for(int i = 0; i < graph[v].size(); i++)
    {
        int child = graph[v][i];

        if(!visited[child])
            dfs(child);
    }
}

int main()
{
    int no_of_points;
    scanf("%d", &no_of_points);

    vector <int> X(no_of_points + 1);
    vector <int> Y(no_of_points + 1);
    for(int i = 1; i <= no_of_points; i++)
        scanf("%d %d", &X[i], &Y[i]);

    int no_of_components = 0;
    for(int i = 1; i <= no_of_points; i++)
    {
        for(int j = 1; j < i; j++)
        {
            if(X[i] == X[j] || Y[i] == Y[j])
            {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    for(int i = 1; i <= no_of_points; i++)
    {
        if(!visited[i])
        {
            no_of_components++;

            dfs(i);
        }
    }

    printf("%d\n", no_of_components - 1);
    return 0;
}
