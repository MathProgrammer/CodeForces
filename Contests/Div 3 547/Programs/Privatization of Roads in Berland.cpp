#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 5;
int no_of_colours = 0;
vector < pair <int, int> > tree[MAX_N];
vector <int> colour(MAX_N, 0);

void dfs(int v, int parent_v, int last_colour)
{
    int next_colour = (last_colour + 1)%no_of_colours;
    
    for(int i = 0; i < tree[v].size(); i++)
    {
        int child_v = tree[v][i].first;
        
        if(child_v == parent_v)
        {
            continue;
        }
        
        colour[tree[v][i].second] = next_colour;
        
        dfs(child_v, v, next_colour);
        
        next_colour = (next_colour + 1)%no_of_colours;
    }
}

int main()
{
    int no_of_vertices, k;
    cin >> no_of_vertices >> k;
    
    vector <int> degree(no_of_vertices + 1, 0);
    int no_of_edges = no_of_vertices - 1;
    for(int i = 1; i <= no_of_edges; i++)
    {
        int u, v;
        cin >> u >> v;
        
        tree[u].push_back(make_pair(v, i));
        tree[v].push_back(make_pair(u, i));
        
        degree[u]++; degree[v]++;
    }
    
    vector <int> frequency(no_of_vertices + 1, 0);
    for(int i = 1; i <= no_of_vertices; i++)
    {
        frequency[degree[i]]++;
    }
    
    vector <int> suffix_sum(no_of_vertices + 5, 0);
    for(int i = no_of_vertices; i >= 1; i--)
    {
        suffix_sum[i] = suffix_sum[i + 1] + frequency[i]; 
    }
    
    for(int i = no_of_vertices; i >= 1; i--)
    {
        if(suffix_sum[i] > k)
        {
            no_of_colours = i;
            break;
        }
    }
    
    dfs(1, 0, -1);
    
    cout << no_of_colours << "\n";
    for(int i = 1; i <= no_of_edges; i++)
    {
        cout << colour[i] + 1 << " ";
    }
    
    cout << "\n";
    return 0;
}
