#include <cstdio>
#include <map>

using namespace std;

const int MAX_A = 3e5 + 5, MAX_N = 8 + 1;
int no_of_arrays, no_of_elements;
long long A[MAX_A][MAX_N];

int possible(int x, int &i, int &j)
{
    map <int, int> map_index;
    
    for(int i = 1; i <= no_of_arrays; i++)
    {
        int mask = 0;
        
        for(int j = 1; j <= no_of_elements; j++)
        {
            if(A[i][j] < x)
                continue;
            
            mask |= (1 << (j - 1));
        }
        
        map_index[mask] = i;
    }
    
    int full_mask = (1 << no_of_elements) - 1;
    
    for(auto it = map_index.begin(); it != map_index.end(); it++)
    {
        int mask = it->first;
        
        for(int m = 0; m <= full_mask; m++)
        {
            if((mask|m) == full_mask && map_index.find(m) != map_index.end())
            {
                i = map_index[mask];
                j = map_index[m];
                
                return true;
            }
        }
    }
    
    return false;
}

int main()
{
    scanf("%d %d", &no_of_arrays, &no_of_elements);
    
    for(int i = 1; i <= no_of_arrays; i++)
    {
        for(int j = 1; j <= no_of_elements; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    
    int left = 0, right = 1e9 + 1;
    int best_i = 1, best_j = 1;
    
    while(right - left > 1)
    {
        int mid = (left + right)/2;
        
        if(possible(mid, best_i, best_j))
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }
    
    printf("%d %d\n", best_i, best_j);
    return 0;
}
