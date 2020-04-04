#include <iostream>

using namespace std;

long long power(long long x, long long p, long long mod)
{
    long long answer = 1;
    
    while(p)
    {
        if(p%2)
        {
            answer = (answer*x)%mod;
        }
        
        x = (x*x)%mod;
        p = p/2;
    }
    
    return answer;
}

int main()
{
    int length;
    cin >> length;
    
    const int MOD = 998244353;
    for(int i = 1; i <= length; i++)
    {
        if(i == length)
        {
            cout << "10\n";
            
            break;
        }
        
        long long no_of_spots = 2, ways_for_block = 10, neighbour = 9;
        long long remaining = power(10, length - i - 1, MOD);
        
        long long corners = (no_of_spots*ways_for_block)*neighbour;
        corners = (corners*remaining)%MOD;
        
        no_of_spots = length - i - 1, ways_for_block = 10, neighbour = 9*9;
        remaining = power(10, length - i - 2, MOD);
        
        long long middle = (no_of_spots*ways_for_block)*neighbour;
        middle = (middle*remaining)%MOD;
        
        long long blocks_here = (corners + middle)%MOD;
        cout << blocks_here << " ";
    }
    
    return 0;
}
