#include <cstdio>
#include <vector>
#include <set>

using namespace std;

const int MAX_N = 2e5 + 15;
set <int> tree[MAX_N];

int main()
{
    int no_of_vertices;
    scanf("%d", &no_of_vertices);

    int no_of_edges = no_of_vertices - 1;
    for(int i = 1; i <= no_of_edges;i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        tree[u].insert(v);
        tree[v].insert(u);
    }

    vector <int> visit_order(no_of_vertices + 1, 0);
    for(int i = 1; i <= no_of_vertices; i++)
        scanf("%d", &visit_order[i]);

    int last = 1;
    int valid_visit_order = (visit_order[1] == 1);

    for(int i = 2; i <= no_of_vertices; i++)
    {
        while(last < i && tree[visit_order[last]].size() == 0)
            last++;

        int head = visit_order[last], v = visit_order[i];

        if(tree[head].count(v) == 1)
        {
            int parent = head, child = v;

            tree[parent].erase(child);
            tree[child].erase(parent);
        }
        else if(tree[head].count(v) == 0)
        {
            valid_visit_order = false;
            break;
        }
    }

    printf(valid_visit_order ? "Yes\n" : "No\n");
    return 0;
}
