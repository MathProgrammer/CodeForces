#include <iostream>

using namespace std;

long long power_mod(long long x, long long power, long long MOD)
{
    long long result = 1;
    
    while(power)
    {
        if(power%2)
            result = (result*x)%MOD;
        
        x = (x*x)%MOD;
        power = power >> 1;
    }
    
    return result;
}

long long inverse(long long x, long long MOD)
{
    return power_mod(x, MOD - 2, MOD);
}

int main()
{
    long long rows, columns, left, right;
    cin >> rows >> columns >> left >> right;
    
    long long grid = rows*columns;
    
    long long answer = 1;
    
    const int MOD = 998244353;
    
    if(grid%2 == 1)
    {
        long long one_cell = right - (left - 1);
        
        answer = power_mod(one_cell, grid, MOD);
    }
    else
    {
        long long one_cell = (right - (left - 1));
        long long even_cells = right/2 - (left - 1)/2;
        long long odd_cells = (right - (left - 1)) - even_cells;
        
        if(one_cell%2 == 0)
        {
            answer = power_mod(one_cell, grid, MOD);
        }
        else
        {
            answer = power_mod(one_cell, grid, MOD) + 1;
        }
        //answer = (power_mod(odd_cells + even_cells, grid, MOD) + power_mod(even_cells - odd_cells, grid, MOD))%MOD;
        answer *= inverse(2, MOD);
        
        answer %= MOD;
    }
    
    cout << answer << "\n";

    return 0;
}
