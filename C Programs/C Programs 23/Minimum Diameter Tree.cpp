#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int no_of_vertices, total_weight;
    scanf("%d %d", &no_of_vertices, &total_weight);

    vector <int> degree(no_of_vertices + 1, 0);
    for(int i = 1; i <= no_of_vertices - 1; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        degree[u]++;
        degree[v]++;
    }

    int no_of_leafs = 0;
    for(int i = 1; i <= no_of_vertices; i++)
        no_of_leafs += (degree[i] == 1);

    double leaf_weight = ( (double) total_weight)/ no_of_leafs;
    double diameter = leaf_weight*2;

    printf("%.12f\n", diameter);
    return 0;
}
