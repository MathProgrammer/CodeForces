#include <iostream>
#include <vector>

using namespace std;

int is_bit_set(long long n, int bit)
{
    return ( (n&(1LL << bit)) != 0 );
}

void solve()
{
    int d, mod;
    cin >> d >> mod;
    
    const int MAX_BITS = 31;
    vector < vector <long long> > no_of_ways(MAX_BITS + 1,
                                             vector <long long> (MAX_BITS + 1, 0));
    
    vector <long long> frequency(MAX_BITS + 1, 0);
    for(int msb = false, bit = MAX_BITS; bit >= 0; bit--)
    {
        if(msb)
        {
            frequency[bit] = (1LL << bit);
            
            continue;
        }
        
        if(is_bit_set(d, bit))
        {
            if(!msb)
            {
                msb = true;
                
                frequency[bit] = d - (1 << bit) + 1;
            }
            
            continue;
        }
    }
    
    for(int length = 1; length <= min(d, MAX_BITS); length++)
    {
        for(int last = 0; last <= MAX_BITS; last++)
        {
            if(length == 1)
            {
                no_of_ways[length][last] = frequency[last];
                
                continue;
            }
            
            for(int second_last = 0; second_last <= last - 1; second_last++)
            {
                no_of_ways[length][last] += (frequency[last]*no_of_ways[length - 1][second_last])%mod;
                
                no_of_ways[length][last] %= mod;
            }
            
       }
    }
    
    long long answer = 0;
    for(int length = 1; length <= MAX_BITS; length++)
    {
        for(int bit = 0; bit <= MAX_BITS; bit++)
        {
            answer += no_of_ways[length][bit];
            
            answer %= mod;
        }
    }
    
    cout << answer << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
