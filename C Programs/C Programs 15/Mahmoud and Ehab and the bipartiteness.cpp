#include <cstdio>
#include <vector>

using namespace std;

const int BLACK = 0, WHITE = 1, NO_OF_COLOURS = 2, MAX_VERTICES = 1e5 + 1;

vector <int> tree[MAX_VERTICES];
int visited[MAX_VERTICES] = {false};
int no_of_elements[NO_OF_COLOURS] = {0};

void dfs_and_colour(int v, int current_colour)
{
    int next_colour = (current_colour + 1)%2;

    if(!visited[v])
    {
        no_of_elements[current_colour]++;
        visited[v] = true;

        for(int i = 0; i < tree[v].size(); i++)
            dfs_and_colour(tree[v][i], next_colour);
    }
}

int main()
{
    int no_of_vertices;
    scanf("%d", &no_of_vertices);

    for(int edge = 1; edge <= no_of_vertices - 1; edge++)
    {
        int x, y;
        scanf("%d %d", &x, &y);

        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    dfs_and_colour(1, BLACK);

    printf("%I64d\n", no_of_elements[BLACK]*1LL*no_of_elements[WHITE] - (no_of_vertices - 1));
    return 0;
}
