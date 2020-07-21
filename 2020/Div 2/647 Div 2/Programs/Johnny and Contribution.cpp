#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define all(v) (v).begin(), (v).end()
using namespace std;

const int MAX_N = 5e5 + 5;
vector <int> graph[MAX_N];
vector <int> colour(MAX_N, 0);
vector <int> mex(MAX_N, 1);
vector <pair <int, int> > desired_colour;

void update_mex(int v)
{
    for(int i = 0; i < graph[v].size(); i++)
    {
        int child = graph[v][i];
        
        if(mex[child] == colour[v])
        {
            mex[child]++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int no_of_vertices, no_of_edges;
    cin >> no_of_vertices >> no_of_edges;
    
    for(int i = 1 ; i <= no_of_edges; i++)
    {
        int u, v;
        cin >> u >> v;
        
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    desired_colour.resize(no_of_vertices + 1);
    for(int i = 1; i <= no_of_vertices; i++)
    {
        cin >> desired_colour[i].first;
        
        desired_colour[i].second = i;
    }
    
    sort(desired_colour.begin() + 1, desired_colour.end());
    
    vector <int> best_order(no_of_vertices + 1, 0);
    for(int i = 1; i <= no_of_vertices; i++)
    {
        if(mex[desired_colour[i].second] != desired_colour[i].first)
        {
            cout << "-1\n";
            
            return 0;
        }
        
        best_order[i] = desired_colour[i].second;
        
        colour[desired_colour[i].second] = desired_colour[i].first;
        
        update_mex(best_order[i]);
    }
    
    for(int i = 1; i <= no_of_vertices; i++)
    {
        cout << best_order[i] << " ";
    }
    
    cout << "\n";
    
    return 0;
    
}
