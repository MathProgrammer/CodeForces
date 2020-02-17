#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

long long count_substrings(long long n)
{
    return (n*(n + 1))/2;
}

void solve()
{
    long long length, no_of_1s;
    cin >> length >> no_of_1s;
    
    long long no_of_0s = (length - no_of_1s);
    
    long long total_substrings = count_substrings(length);
    
    long long dividers = (no_of_1s + 1);
    
    long long full_zero_islands_size = (no_of_0s/dividers);
    
    long long zero_substrings = dividers*count_substrings(full_zero_islands_size);
    
    if(no_of_0s%dividers != 0)
    {
        long long remaining_zeroes = no_of_0s - dividers*(full_zero_islands_size);
        
        zero_substrings += remaining_zeroes*(full_zero_islands_size + 1);
    }
    
    long long one_substrings = total_substrings - zero_substrings;
    
    cout << one_substrings << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
