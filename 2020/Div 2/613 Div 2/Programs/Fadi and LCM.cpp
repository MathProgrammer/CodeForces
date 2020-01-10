#include <iostream>
#include <vector>

using namespace std;

int is_bit_set(long long n, int bit)
{
    return ( ( n&(1LL << bit) ) != 0);
}

void factorise(long long x, vector <long long> &P)
{
    for(long long i = 2; i*i <= x; i++)
    {
        if(x%i == 0)
        {
            long long p = 1;
            
            while(x%i == 0)
            {
                x /= i;
                
                p *= i;
            }
            
            P.push_back(p);
        }
    }
    
    if(x > 1)
    {
        P.push_back(x);
    }
}

int main()
{
    long long n;
    cin >> n;
    
    vector <long long> prime_factors;
    factorise(n, prime_factors);
    
    long long best_x = 1, best_y = n;
    int number_of_uniques = prime_factors.size();
    for(long long mask = 0; mask < (1LL << number_of_uniques); mask++)
    {
        long long x = 1, y = 1;
        for(int bit = 0; bit < number_of_uniques; bit++)
        {
            if(is_bit_set(mask, bit))
            {
               x *= prime_factors[bit];
            }
            else
            {
                y *= prime_factors[bit];
            }
        }
        
        if(max(x, y) < max(best_x, best_y))
        {
            best_x = x;
            best_y = y;
        }
    }
    
    cout << best_x << " " << best_y << "\n";
    
    return 0;
}
