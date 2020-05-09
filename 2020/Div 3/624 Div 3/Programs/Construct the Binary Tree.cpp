#include <iostream>
#include <vector>

using namespace std;

int is_power_of_2(int n)
{
    return ( (n&(n - 1)) == 0 );
}

void solve()
{
    int no_of_vertices, total_depth_sum;
    cin >> no_of_vertices >> total_depth_sum;
    
    long long maximum_sum = (no_of_vertices*(no_of_vertices - 1))/2;
    long long minimum_sum = 0;
    for(int i = 1, level = 0; i <= no_of_vertices; i++)
    {
        if(is_power_of_2(i))
        {
            level++;
        }
        
        minimum_sum += (level - 1);
    }
    
    if(total_depth_sum < minimum_sum || maximum_sum < total_depth_sum)
    {
        cout << "NO\n";
        
        return;
    }
    
    vector <int> depth(no_of_vertices + 1, 0);
    vector <int> parent(no_of_vertices + 1, 0);
    vector <int> no_of_children(no_of_vertices + 1, 1);
    for(int i = 1; i <= no_of_vertices; i++)
    {
        parent[i] = i - 1;
        depth[i] = i - 1;
    }
    
    no_of_children[no_of_vertices] = 0;
    
    vector <int> immobile(no_of_vertices + 1, false);
    
    for(long long sum = maximum_sum; sum > total_depth_sum; )
    {
        int first_v = 0;
        for(int i = 1; i <= no_of_vertices; i++)
        {
            if(!immobile[i] && no_of_children[i] == 0 &&
               (first_v == 0 || depth[i] < depth[first_v]))
            {
                first_v = i;
            }
        }
        
        int best_parent = 0;
        for(int i = 1; i <= no_of_vertices; i++)
        {
            if(depth[i] == depth[first_v] - 2 && no_of_children[i] < 2)
            {
                best_parent = i;
            }
        }
        
        if(best_parent == 0)
        {
            immobile[first_v] = true;
            continue;
        }
        
        sum--;
        
        no_of_children[parent[first_v]]--;
        depth[first_v]--;
        
        parent[first_v] = best_parent;
        no_of_children[best_parent]++;
    }
    
    cout << "YES\n";
    for(int i = 2; i <= no_of_vertices; i++)
    {
        cout << parent[i] << " ";
    }
    
    cout << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
