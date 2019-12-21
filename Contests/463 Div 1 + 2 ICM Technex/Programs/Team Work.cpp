#include <iostream>
#include <cstring>

using namespace std;

const int MAX_N = 5005, MOD = 1e9 + 7;
long long no_of_ways[MAX_N][MAX_N];

long long power_mod(long long x, long long power)
{
    long long result = 1;
    
    while(power)
    {
        if(power%2 == 1)
            result = (result*x)%MOD;
        
        x = (x*x)%MOD;
        power = power >> 1;
    }
    
    return result;
}

long long f(long long differentiations, long long b, long long c)
{
    if(no_of_ways[differentiations][b] != -1)
    {
        return no_of_ways[differentiations][b];
    }
    
    //x^b(1 + x)^c becomes x[bx^{b - 1}(1 + x)^c + cx^b(1 + x)^{c - 1}]
    //f(a, b, c) = b.f(a - 1, b, c) + c.f(a - 1, b + 1, c - 1)
    
    if(differentiations == 0)
    {
        return no_of_ways[differentiations][b] = power_mod(2, c);
    }
    
    long long term_1 = b*f(differentiations - 1, b, c);
    long long term_2 = (c == 0 ? 0 : c*f(differentiations - 1, b + 1, c - 1));
    
    return no_of_ways[differentiations][b] = (term_1 + term_2)%MOD;
}

int main()
{
    long long no_of_people, k;
    cin >> no_of_people >> k;
    
    memset(no_of_ways, -1, sizeof(no_of_ways));
    cout << f(k, 0, no_of_people) << "\n";
    
    return 0;
}
