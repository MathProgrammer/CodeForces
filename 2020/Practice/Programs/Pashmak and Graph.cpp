#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin() + 1, (v).end()
using namespace std;

struct Edge
{
    int source, destination, weight;

    int operator <(const Edge &A)
    {
        return (weight < A.weight);
    }
};

int main()
{
    int no_of_vertices, no_of_edges;
    scanf("%d %d", &no_of_vertices, &no_of_edges);

    vector <Edge> edge(no_of_edges + 1);
    for(int i = 1; i <= no_of_edges; i++)
    {
        scanf("%d %d %d", &edge[i].source, &edge[i].destination, &edge[i].weight);
    }

    sort(all(edge));

    vector <int> maximum_ending_at(no_of_vertices + 1, 0);

    vector <int> maximum_with_this_weight(no_of_vertices + 1, 0);
    
    for(int i = 1; i <= no_of_edges; )
    {
        int j = i;

        for(j = i; j <= no_of_edges && edge[j].weight == edge[i].weight; j++)
        {
            maximum_with_this_weight[edge[j].destination] = 0;
        }
        
        //Process all edges having this weight. Have a different vector so you don't interact with equal weights.
        for(j = i; j <= no_of_edges && edge[j].weight == edge[i].weight; j++)
        {
            maximum_with_this_weight[edge[j].destination] = max(maximum_with_this_weight[edge[j].destination], 1 + maximum_ending_at[edge[j].source]);
        }

        for(j = i; j <= no_of_edges && edge[j].weight == edge[i].weight; j++)
        {
            maximum_ending_at[edge[j].destination] = max(maximum_ending_at[edge[j].destination], maximum_with_this_weight[edge[j].destination]);
        }

        i = j;
    }

    int maximum_path = 0;
    for(int i = 1; i <= no_of_vertices; i++)
        maximum_path = max(maximum_path, maximum_ending_at[i]);

    printf("%d\n", maximum_path);
    return 0;
}
