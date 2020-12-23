#include <iostream>

using namespace std;

pair <int, int> max_min_digit(long long n)
{
    pair <int, int> max_min = make_pair(0, 10);
    
    while(n)
    {
        int digit = n%10;
        
        max_min.first = max(max_min.first, digit);
        max_min.second = min(max_min.second, digit);
        
        n /= 10;
    }
    
    return max_min;
}

void solve()
{
    long long n, k;
    cin >> n >> k;
    
    for(int i = 2; i <= k && max_min_digit(n).second != 0; i++)
    {
        n += max_min_digit(n).first*max_min_digit(n).second;
    }
    
    cout << n << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
