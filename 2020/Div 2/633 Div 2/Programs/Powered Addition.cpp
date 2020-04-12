#include <iostream>
#include <vector>

using namespace std;

int is_bit_set(long long n, int bit)
{
    return ( (n&(1LL << bit)) != 0);
}

int msb(long long n)
{
    const int MAX_BIT = 63;
    for(int bit = MAX_BIT; bit >= 0; bit--)
    {
        if(is_bit_set(n, bit))
        {
            return bit;
        }
    }
    
    return 0;
}

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    vector <long long> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    int time_required = 0;
    long long max_so_far = A[1];
    for(int i = 1; i <= no_of_elements; i++)
    {
        if(A[i] >= max_so_far)
        {
            max_so_far = A[i];
            continue;
        }
        
        long long required = max_so_far - A[i]; 
        time_required = max(time_required, msb(required) + 1);
        
        max_so_far = A[i] + required;
    }
    
    cout << time_required << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
