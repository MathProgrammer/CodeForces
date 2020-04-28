#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define all(v) (v).begin() + 1, (v).end()
using namespace std;

const int MAX_N = 1e5 + 5, MAX_M = (1 << 7) + 1;
long long max_till[MAX_N][MAX_M], value[MAX_N][9];

int no_of_bits(int n)
{
    int count = 0;
    
    while(n)
    {
        count += (n%2);
        
        n /= 2;
    }
    
    return count;
}

int is_bit_set(int n, int bit)
{
    return ( (n & (1 << bit)) != 0);
}

int main()
{
    int no_of_elements, no_of_players, audience;
    cin >> no_of_elements >> no_of_players >> audience;
    
    vector < pair<int, int> > A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i].first;
        
        A[i].second = i;
    }
    
    sort(all(A));
    reverse(all(A));
    
    for(int i = 1; i <= no_of_elements; i++)
    {
        for(int j = 0; j < no_of_players; j++)
        {
            cin >> value[i][j];
        }
    }
    
    memset(max_till, -1, sizeof(max_till));
    max_till[0][0] = 0;
    
    for(int i = 1; i <= no_of_elements; i++)
    {
        int index = A[i].second; //cout << "(" << A[i].first << "," << A[i].second << ")\n";
        
        for(int m = 0; m < (1 << no_of_players); m++)
        {
            int players = no_of_bits(m);
            int audience_so_far = (i - 1) - players;
            
            if(players > i)
            {
                continue;
            }
            
            if(audience_so_far < audience)
            {
                if(max_till[i - 1][m] != -1)
                {   //cout << "Audience = " << A[i].first << "\n";
                    max_till[i][m] = max_till[i - 1][m] + A[i].first;
                }
            }
            else
            {
                if(max_till[i - 1][m] != -1)
                {
                    max_till[i][m] = max_till[i - 1][m];
                }
            }
            
            for(int bit = 0; bit < no_of_players; bit++)
            {
                if(is_bit_set(m, bit) && max_till[i - 1][m^(1 << bit)] != -1)
                {
                    //cout << "Choice is " << max_till[i][m] << " and " << value[index][bit] << " + " << max_till[i - 1][m^(1 << bit)] << "\n";
                    
                    max_till[i][m] = max(max_till[i][m],
                                         value[index][bit] + max_till[i - 1][m^(1 << bit)]);
                }
            }
            
            //cout << "f(" << i << "," << m << ") = " << max_till[i][m] << "\n";
        }
    }
    
    int total = (1 << no_of_players) - 1;
    cout << max_till[no_of_elements][total] << "\n";
    
    return 0;
}
