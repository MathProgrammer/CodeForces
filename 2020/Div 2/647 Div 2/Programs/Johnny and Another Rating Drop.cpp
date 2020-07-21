#include <iostream>
#include <vector>

using namespace std;

int is_bit_set(long long n, int bit)
{
    return ( (n& (1LL << bit)) != 0 );
}

long long ceil(long long n, long long d)
{
    return (n/d) + (n%d != 0);
}

void solve()
{
    long long n;
    cin >> n;
    
    long long answer = 0;
    
    const int MAX_BITS = 63;
    
    int msb = 0;
    for(int bit = 0; bit < MAX_BITS; bit++)
    {
        if(is_bit_set(n, bit))
        {
            msb = bit;
        }
    }
    
    for(int bit = 0; bit <= msb; bit++)
    {
        long long p = (1LL << bit);
        
        long long no_of_blocks = n/p + 1;
        
        answer += no_of_blocks - 1;
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
