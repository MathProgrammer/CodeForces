#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long t, left, right;
    cin >> t >> left >> right;
    
    const int MOD = 1e9 + 7;
    vector <long long> largest_prime_factor(right + 1, 0);
    vector <long long> minimum_comparisons(right + 1, 1e16);
    minimum_comparisons[1] = 0;
    for(long long i = 2; i <= right; i++)
    {
        if(largest_prime_factor[i] == 0)
        {
            largest_prime_factor[i] = i;
            for(long long multiple = i*i; multiple <= right; multiple += i)
            {
                if(largest_prime_factor[multiple] == 0)
                {
                    largest_prime_factor[multiple] = i;
                }
            }
        }
        
        for(int x = i; x != 1; x /= largest_prime_factor[x])
        {
            int remaining = i/largest_prime_factor[x];
            
            long long comparisons_here = (i*(largest_prime_factor[x] - 1))/2 + minimum_comparisons[remaining];
            
            minimum_comparisons[i] = min(minimum_comparisons[i], comparisons_here);
        }
        
        minimum_comparisons[i] %= MOD;
    }
    
    long long answer = 0, coefficient = 1;
    for(int i = left; i <= right; i++)
    {
        answer += (coefficient*minimum_comparisons[i])%MOD;
        
        coefficient = (coefficient*t)%MOD;
        
        answer %= MOD;
    }
    
    cout << answer << "\n";
    return 0;
}
