#include <cstdio>

int main()
{
    int no_of_vertices;
    scanf("%d", &no_of_vertices);

    int no_of_children[no_of_vertices + 1] = {0};
    int parent[no_of_vertices + 1];

    for(int i = 2; i <= no_of_vertices; i++)
    {
        scanf("%d", &parent[i]);

        no_of_children[parent[i]]++;
    }

    int no_of_leaf_children[no_of_vertices + 1] = {0};
    for(int i = 1; i <= no_of_vertices; i++)
    {
        if(no_of_children[i] == 0)
        {
            no_of_leaf_children[parent[i]]++;
        }
    }

    int is_spruce = true;
    for(int i = 1; i<= no_of_vertices; i++)
    {
        if(no_of_children[i] > 0 && no_of_leaf_children[i] < 3)
        {
            is_spruce = false;
            break;
        }
    }

    printf(is_spruce ? "Yes\n" : "No\n");
    return 0;
}
