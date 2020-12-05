#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

const int MAX_N = 5e5 + 5;
vector <int> tree[MAX_N];

vector <int> depths;

void dfs(int v, int parent_v, int depth)
{
    if(tree[v].size() == 1)
    {
        depths.push_back(depth);
    }
    
    for(int child_v : tree[v])
    {
        if(child_v == parent_v)
        {
            continue;
        }
        
        dfs(child_v, v, depth + 1);
    }
}

int get_answer(int v)
{
    dfs(v, 1, 0);
    
    sort(all(depths));
    
    vector <int> visit_order(depths.size());
    for(int i = 0; i < visit_order.size(); i++)
    {
        visit_order[i] = depths[i];
        
        if(i > 0)
        {
            visit_order[i] = max(visit_order[i - 1] + 1, visit_order[i]);
        }
    }
    
    depths.clear();
    //cout << " Answer here = " << visit_order.back() << "\n";
    return visit_order.back();
}

int main()
{
    int no_of_vertices;
    cin >> no_of_vertices;
    
    for(int i = 1, no_of_edges = no_of_vertices - 1; i <= no_of_edges; i++)
    {
        int u, v;
        cin >> u >> v;
        
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    int answer = 0;
    
    for(int child : tree[1])
    {
        answer = max(answer, get_answer(child) + 1); //cout << child << " ";
    }
    
    cout << answer << "\n";
    return 0;
}
