#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 5e5 + 5;
int available = 1;
vector <int> tree[MAX_N];
int left_label[MAX_N], right_label[MAX_N];

void dfs(int v, int parent_v)
{   //cout << "At " << v << "\n";
    int no_of_children = tree[v].size() - (parent_v == 0 ? 0 : 1);
    
    available += no_of_children + 1;

    right_label[v] = available;
    //cout << "Size " << v << " = " << tree[v].size() << "\n";
    for(int i = 0, child_no = 0; i < tree[v].size(); i++)
    {
        int child_v = tree[v][i];
        
        if(child_v == parent_v)
        {
            continue;
        }
        
        child_no++;
        
        left_label[child_v] = right_label[v] - child_no;
        
        //cout << "Child = " << child_v << "\n";
        dfs(child_v, v);
    }
}

int main()
{
    int no_of_vertices;
    scanf("%d", &no_of_vertices);
    
    int no_of_edges = no_of_vertices - 1;
    
    for(int i = 1; i <= no_of_edges; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    left_label[1] = available;
    
    dfs(1, 0);
    
    for(int i = 1; i <= no_of_vertices; i++)
    {
        cout << left_label[i] << " " << right_label[i] << "\n";
    }
    
    return 0;
}
