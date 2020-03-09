#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector <set <int> > tree;
set <int> leaves;

void erase_till(int v, int child, int destination)
{
    if(leaves.find(v) != leaves.end())
    {
        leaves.erase(v);
    }
    
    for(auto it = tree[v].begin(); it != tree[v].end(); it++)
    {
        int parent = *it;
        
        if(parent == child)
        {
            continue;
        }
        
        if(parent == destination)
        {
            tree[destination].erase(v);
            
            continue;
        }
        
        if(tree[parent].size() > 0)
        {
            erase_till(parent, v, destination);
        }
    }
    
    tree[v].clear();
}

int main()
{
    int no_of_vertices;
    cin >> no_of_vertices;
    
    tree.resize(no_of_vertices + 1);
    int no_of_edges = no_of_vertices - 1;
    for(int i = 1; i <= no_of_edges; i++)
    {
        int u, v;
        cin >> u >> v;
        
        tree[u].insert(v);
        tree[v].insert(u);
    }
    
    for(int v = 1; v <= no_of_vertices; v++)
    {
        if(tree[v].size() == 1)
        {
            leaves.insert(v);
        }
    }
    
    int root = 0;
    while(leaves.size() > 1)
    {
        int u = *(leaves.begin()); leaves.erase(u);
        int v = *(leaves.begin()); leaves.erase(v);
        
        int w;
        cout << "? " << u << " " << v << "\n" << flush;
        cin >> w;
        
        if(w == u || w == v)
        {
            root = w;
            break;
        }
        
        erase_till(u, 0, w);
        erase_till(v, 0, w);
        
        if(tree[w].size() <= 1)
        {
            leaves.insert(w);
        }
    }
    
    if(root == 0)
    {
        root = *(leaves.begin());
    }
    
    cout << "! " << root << "\n" << flush;
    return 0;
}
