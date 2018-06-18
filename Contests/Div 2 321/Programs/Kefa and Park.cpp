#include <cstdio>
#include <vector>

using namespace std;

const int MAX_VERTICES = 2e5 + 1;
int visited[MAX_VERTICES] = {false};
int has_cat[MAX_VERTICES] = {false};
int no_of_consecutive_cats_till[MAX_VERTICES] = {0};
vector <int> tree[MAX_VERTICES];

int max_cats;

void dfs(int current_park, int &no_of_paths)
{
    if(tree[current_park].size() == 1 && visited[tree[current_park][0]])
        no_of_paths++;

    for(int i = 0; i < tree[current_park].size(); i++)
    {
        int next_park = tree[current_park][i];

        if(!visited[next_park])
        {
            visited[next_park] = true;

            no_of_consecutive_cats_till[next_park] = (has_cat[next_park] ? no_of_consecutive_cats_till[current_park] + 1 : 0);

            if(no_of_consecutive_cats_till[next_park] <= max_cats)
                dfs(next_park, no_of_paths);
        }
    }
}

int main()
{
    int no_of_vertices;
    scanf("%d %d", &no_of_vertices, &max_cats);

    for(int i = 1; i <= no_of_vertices; i++)
        scanf("%d", &has_cat[i]);

    for(int i = 1; i <= no_of_vertices - 1; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);

        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    no_of_consecutive_cats_till[1] = has_cat[1];
    visited[1] = true;
    int no_of_paths = 0;

    dfs(1, no_of_paths);

    printf("%d\n", no_of_paths);
    return 0;
}
