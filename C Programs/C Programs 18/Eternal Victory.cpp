#include <cstdio>
#include <vector>

using namespace std;

const int MAX_CITIES = 1e5 + 5;

vector <pair <int, int> > tree[MAX_CITIES];
int max_distance[MAX_CITIES];

void dfs(int v, int parent_v)
{
        max_distance[v] = 0;

        for(int i = 0; i < tree[v].size(); i++)
        {
            int child_v = tree[v][i].first;
            int child_distance = tree[v][i].second;

            if(child_v == parent_v)
                continue;

            dfs(child_v, v);

            max_distance[v] = max(max_distance[v], child_distance + max_distance[child_v]);
        }
}

int main()
{
    int no_of_cities;
    scanf("%d", &no_of_cities);

    long long sum_of_edges = 0;

    for(int i = 1; i < no_of_cities; i++)
    {
        int x, y, weight;
        scanf("%d %d %d", &x, &y, &weight);

        tree[x].push_back(make_pair(y, weight));
        tree[y].push_back(make_pair(x, weight));

        sum_of_edges += weight;
    }

    dfs(1, 0);

    long long total_travel_distance = (sum_of_edges == max_distance[1] ? sum_of_edges : 2*sum_of_edges - max_distance[1]);

    printf("%I64d\n", total_travel_distance);
    return 0;
}
