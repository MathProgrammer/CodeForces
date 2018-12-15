#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 3e5 + 5, NOT_KNOWN = -1, MOD = 998244353;
vector <int> graph[MAX_N];
vector <int> colour(MAX_N, NOT_KNOWN);

long long power_mod(long long base, long long power)
{
    long long result = 1;

    while(power)
    {
        if(power%2 == 1)
            result = (result*base)%MOD;

        base = (base*base)%MOD;
        power = power >> 1;
    }

    return result;
}

void clean_for_next_query(int limit)
{
    for(int i = 0; i <= limit; i++)
    {
        graph[i].clear();

        colour[i] = NOT_KNOWN;
    }
}

int get_complement(int x) //Return 1 if 0 and 0 if 1
{
    return (1 - x);
}

long long get_component_answer_bfs(int source)
{
    queue <int> Q;
    Q.push(source);

    colour[source] = 1;

    vector <long long> component(2, 0);
    component[colour[source]]++;

    long long this_component_answer = 1;

    while(!Q.empty())
    {
        int current_v = Q.front();

        Q.pop();

        for(int i = 0; i < graph[current_v].size(); i++)
        {
            int child_v = graph[current_v][i];

            if(colour[child_v] == NOT_KNOWN)
            {
                colour[child_v] = get_complement(colour[current_v]);

                component[colour[child_v]]++;

                Q.push(child_v);
            }
            else if(colour[child_v] == colour[current_v]) //It's not bipartite
            {
                return 0;
            }
        }
    }

    this_component_answer = (power_mod(2, component[0]) + power_mod(2, component[1]))%MOD;

    return this_component_answer;
}

void solve()
{
    int no_of_vertices, no_of_edges;
    scanf("%d %d", &no_of_vertices, &no_of_edges);

    for(int i = 1; i <= no_of_edges; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    long long answer = 1;

    for(int i = 1; i <= no_of_vertices; i++)
    {
        if(colour[i] == NOT_KNOWN)
            answer = (answer*get_component_answer_bfs(i))%MOD;
    }

    printf("%I64d\n", answer);

    clean_for_next_query(no_of_vertices);
}

int main()
{
    int no_of_queries;
    scanf("%d", &no_of_queries);

    while(no_of_queries--)
        solve();

    return 0;
}
