#include <iostream>
#include <vector>

using namespace std;

int is_bit_set(long long n, int bit)
{
    return ( (n&(1LL << bit)) != 0);
}

void solve()
{
    long long n, no_of_boxes;
    cin >> n >> no_of_boxes;
    
    const int MAX_BITS = 61;
    
    long long sum = 0;
    vector <long long> frequency(MAX_BITS, 0);
    for(int i = 1; i <= no_of_boxes; i++)
    {
        long long box;
        cin >> box;
        
        for(int bit = 0; bit < MAX_BITS; bit++)
        {
            if( (1LL << bit) == box)
            {
                frequency[bit]++;
            }
        }
        
        sum += box;
    }
    
    if(sum < n)
    {
        cout << "-1\n";
        
        return;
    }
    
    int minimum_divisions = 0;
    for(int bit = 0; bit < MAX_BITS; bit++)
    {
        if(bit >= 1)
            frequency[bit] += frequency[bit - 1]/2;
        
        if(is_bit_set(n, bit) && frequency[bit] == 0)
        {
            int source;
        
            for(source = bit; source < MAX_BITS; source++)
            {
                if(frequency[source] >= 1)
                {
                    break;
                }
            }
            
            //cout << "Source = " << source << " Bit = " << bit << "\n";
            for(int i = source; i > bit; i--)
            {
                frequency[i]--;
                frequency[i - 1] += 2;
                
                minimum_divisions++;
            }
        }
        
        if(is_bit_set(n, bit))
        {
            frequency[bit]--;
        }
    }
    
    cout << minimum_divisions << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
