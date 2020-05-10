#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 5;
vector <int> graph[MAX_N], reverse_graph[MAX_N];
vector <int> visited(MAX_N, false);
vector <int> on_stack(MAX_N, false);
vector <int> visited_reverse(MAX_N, false), on_stack_reverse(MAX_N, 0);

int dfs_cycle_reverse(int v)
{
    visited_reverse[v] = true;
    on_stack_reverse[v] = true;
    
    for(int i = 0; i < reverse_graph[v].size(); i++)
    {
        int child_v = reverse_graph[v][i];
        
        if(visited_reverse[child_v] && on_stack_reverse[child_v])
        {   
            return true;
        }
        
        if(!visited_reverse[child_v] && dfs_cycle_reverse(child_v))
        {
            return true;
        }
    }
    
    on_stack_reverse[v] = false;
    
    return false;
}

int dfs_cycle(int v)
{
    visited[v] = true;
    on_stack[v] = true;
    
    for(int i = 0; i < graph[v].size(); i++)
    {
        int child_v = graph[v][i];
        
        if(visited[child_v] && on_stack[child_v])
        {
            return true;
        }
        
        if(!visited[child_v] && dfs_cycle(child_v))
        {
            return true;
        }
    }
    
    on_stack[v] = false;
    
    return false;
}

int main()
{
    int no_of_variables, no_of_inequalities;
    cin >> no_of_variables >> no_of_inequalities;
    
    vector <int> indegree(no_of_variables + 1, 0);
    for(int i = 1; i <= no_of_inequalities; i++)
    {
        int u, v;
        cin >> u >> v;
        
        graph[u].push_back(v);
        reverse_graph[v].push_back(u);
        
        indegree[v]++; //cout << "In Degree " << v << " = " << indegree[v] << "\n";
    }
    
    int no_of_universals = 0;
    string answer;
    for(int i = 1; i <= no_of_variables; i++)
    {
        if(!visited[i] && !visited_reverse[i])
        {
            no_of_universals++;
            
            answer += 'A';
        }
        else
        {
            answer += 'E';
        }
        
        if(dfs_cycle(i) || dfs_cycle_reverse(i))
        {
            cout << "-1\n";
            
            return 0;
        }
    }
    
    cout << no_of_universals << "\n";
    cout << answer << "\n";
    return 0;
}
