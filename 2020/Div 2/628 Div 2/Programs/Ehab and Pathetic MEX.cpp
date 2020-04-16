#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

const int MAX_N = 1e5 + 5;
vector <set <int> > tree;
queue <int> leaves;

void remove(int u, int v)
{
    tree[u].erase(v);
    tree[v].erase(u);
    
    if(tree[u].size() == 1)
    {
        leaves.push(u);
    }
    
    if(tree[v].size() == 1)
    {
        leaves.push(v);
    }
}

int main()
{
    int no_of_vertices;
    cin >> no_of_vertices;
    
    int no_of_edges = no_of_vertices - 1;
    tree.resize(no_of_vertices + 1);
    map <pair <int, int>, int> edge_no;
    
    for(int i = 1; i <= no_of_edges; i++)
    {
        int u, v;
        cin >> u >> v;
        
        tree[u].insert(v);
        tree[v].insert(u);
        
        edge_no[make_pair(u, v)] = i;
        edge_no[make_pair(v, u)] = i;
    }
    
    for(int i = 1; i <= no_of_vertices; i++)
    {
        if(tree[i].size() == 1)
        {
            leaves.push(i);
        }
    }
    
    int last_label = 0;
    vector <int> label(no_of_edges + 1, 0);
    while(leaves.size() > 0)
    {
        int current_v = leaves.front();
        
        leaves.pop();
        
        auto v_it = tree[current_v].begin();
        
        int current_u = *v_it;
        
        remove(current_u, current_v);
        
       /* cout << "L = " << current_v << "," << current_u
        << " Edge No = " << edge_no[make_pair(current_u, current_v)] <<
        " edgeLabel = " << last_label << "\n";*/
        label[edge_no[make_pair(current_u, current_v)]] = last_label++;
    }
    
    
    
    for(int i = 1; i <= no_of_edges; i++)
    {
        cout << label[i] << "\n";
    }
    
    return 0;
}
