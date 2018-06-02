#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

#define all(v) (v).begin(). (v).end()
using namespace std;

const int MAX_N = 1e5 + 15, MAX_COLOURS = 105, oo = 1e9;

vector <int> graph[MAX_N];
vector <int> has_colour[MAX_COLOURS];
int answer[MAX_N][MAX_COLOURS];

int main()
{
    int no_of_vertices, no_of_edges, no_of_colours, required_colours;
    scanf("%d %d %d %d", &no_of_vertices, &no_of_edges, &no_of_colours, &required_colours);

    vector <int> colour(no_of_vertices + 1);
    for(int i = 1; i <= no_of_vertices; i++)
    {
        scanf("%d", &colour[i]);
        has_colour[colour[i]].push_back(i);
    }

    for(int i = 1; i <= no_of_edges; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int c = 1; c <= no_of_colours; c++)
    {
        queue <int> Q;
        vector <int> distance(no_of_vertices + 1, oo);

        for(int i = 0; i < has_colour[c].size(); i++)
        {
            int v = has_colour[c][i];

            distance[v] = 0;
            Q.push(v);
        }

        while(!Q.empty())
        {
            int v = Q.front();
            Q.pop();

            for(int i = 0; i < graph[v].size(); i++)
            {
                int child = graph[v][i];

                if(distance[child] > distance[v] + 1)
                {
                    distance[child] = distance[v] + 1;
                    Q.push(child);
                }
            }
        }

        for(int v = 1; v <= no_of_vertices; v++)
        {
            answer[v][c] = distance[v];
        }
    }

    for(int v = 1; v <= no_of_vertices; v++)
    {
        sort(answer[v] + 1, answer[v] + no_of_colours + 1);

        long long cost = 0;
        for(int c = 1; c <= required_colours; c++)
            cost += answer[v][c];

        printf("%I64d ", cost);
    }

    return 0;
}
