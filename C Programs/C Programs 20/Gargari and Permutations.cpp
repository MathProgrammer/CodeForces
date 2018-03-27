#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_N = 1005, MAX_PERMUTATIONS = 5;
int P[MAX_PERMUTATIONS + 1][MAX_N];
int position[MAX_PERMUTATIONS + 1][MAX_N];

vector <int> graph[MAX_N];
int longest_path[MAX_N];

int get_longest_path(int v)
{
    if(longest_path[v] != -1)
        return longest_path[v];

    longest_path[v] = 1;

    for(int i = 0; i < graph[v].size(); i++)
    {
        int child = graph[v][i];

        longest_path[v] = max(longest_path[v], 1 + get_longest_path(child));
    }

    return longest_path[v];
}

int main()
{
    int no_of_permutations, length;
    scanf("%d %d", &length, &no_of_permutations);

    for(int k = 1; k <= no_of_permutations; k++)
    {
        for(int i = 1; i <= length; i++)
        {
            int element;
            scanf("%d", &element);
            position[k][element] = i;
        }
    }

    for(int i = 1; i <= length; i++)
    {
        for(int j = i + 1; j <= length; j++)
        {
            int i_always_before_j = true, j_always_before_i = true;

            for(int k = 1; k <= no_of_permutations; k++)
            {
                if(position[k][i] > position[k][j])
                {
                    i_always_before_j = false;
                }
                if(position[k][j] > position[k][i])
                {
                    j_always_before_i = false;
                }
            }

            if(i_always_before_j)
            {
                graph[i].push_back(j);
            }
            if(j_always_before_i)
            {
                graph[j].push_back(i);
            }
        }
    }

    memset(longest_path, -1, sizeof(longest_path));
    int graph_longest_path = 0;
    for(int i = 1; i <= length; i++)
        graph_longest_path = max(graph_longest_path, get_longest_path(i));

    printf("%d\n", graph_longest_path);

    return 0;
}
