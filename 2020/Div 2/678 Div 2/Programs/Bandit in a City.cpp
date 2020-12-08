#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 5;

long long leaves[MAX_N], maximum[MAX_N], sum[MAX_N], A[MAX_N];
vector <int> tree[MAX_N];

long long ceil(long long n, long long d)
{
    return (n/d) + (n%d != 0 ? 1 : 0);
}

void dfs(int v)
{
    sum[v] = A[v];
    
    if(tree[v].size() == 0)
    {
        leaves[v] = 1;
        
        maximum[v] = sum[v];
        
        return;
    }
    
    for(int child_v : tree[v])
    {
        dfs(child_v);
        
        leaves[v] += leaves[child_v];
        
        sum[v] += sum[child_v];
        
        maximum[v] = max(maximum[v], maximum[child_v]);
    }
    
    maximum[v] = max(maximum[v], ceil(sum[v], leaves[v]));
}

int main()
{
    int no_of_vertices;
    cin >> no_of_vertices;
    
    for(int i = 2; i <= no_of_vertices; i++)
    {
        int source;
        cin >> source;
        
        tree[source].push_back(i);
    }
    
    for(int i = 1; i <= no_of_vertices; i++)
    {
        cin >> A[i];
        
        leaves[i] = 0;
        maximum[i] = 0;
    }
    
    dfs(1);
    
    cout << maximum[1] << "\n";
    return 0;
}
