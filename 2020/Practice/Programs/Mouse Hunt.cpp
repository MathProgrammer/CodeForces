#include <iostream>
#include <vector>

using namespace std;

vector <int> cost, to, visits, current_dfs;
vector < vector <int> > cycle;

void dfs(int v, int &total_cost)
{
    //Cycle Starts here
    if(current_dfs[v])
    {
        int cost_here = cost[v];
        
        for(int i = to[v]; i != v; i = to[i])
        {   
            cost_here = min(cost_here, cost[i]);
        }
        
        total_cost += cost_here;
        return;
    }
    else if(visits[v]) //It was already linked to a cycle from some other dfs
    {
        return;
    }
    
    visits[v] = true;
    
    current_dfs[v] = true;
    
    dfs(to[v], total_cost);
    
    current_dfs[v] = false;
}

int main()
{
    int no_of_vertices;
    cin >> no_of_vertices;
    
    cost.resize(no_of_vertices + 1);
    for(int i = 1; i <= no_of_vertices; i++)
    {
        cin >> cost[i];
    }
    
    to.resize(no_of_vertices + 1);
    for(int i = 1; i <= no_of_vertices; i++)
    {
        cin >> to[i];
    }
    
    int total_cost = 0;
    current_dfs.resize(no_of_vertices + 1, 0);
    visits.resize(no_of_vertices + 1, 0);
    for(int i = 1; i <= no_of_vertices; i++)
    {
        if(!visits[i])
        {
            dfs(i, total_cost);
        }
    }
    
    cout << total_cost << "\n";
    return 0;
}
