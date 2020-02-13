#include <iostream>

using namespace std;

long long ceil(long long n, long long d)
{
    return (n/d + (n%d != 0));
}

int possible(long long x, long long n, long long g, long long b)
{
   long long half = ceil(n, 2);
    
    long long no_of_cycles = x/(g + b);
    
    long long extra = x - no_of_cycles*(g + b);
    long long extra_good = 0, extra_bad = 0;
    
    if(extra > 0)
    {
        extra_good = min(g, extra);
        
        extra -= extra_good;
    }
    
    if(extra > 0)
    {
        extra_bad = min(b, extra);
        
        extra -= extra_bad;
    }
    
    long long total_good = no_of_cycles*g + extra_good;
    long long total_bad = no_of_cycles*b + extra_bad;
    
    if(total_good < half|| total_good + total_bad < n)
    {
        return false;
    }
    
    return true;
}

void solve()
{
    long long no_of_days, good_days, bad_days;
    cin >> no_of_days >> good_days >> bad_days;
    
    const long long oo = 1e18;
    long long left = 0, right = oo;
    while(right - left > 1)
    {
        long long mid = (left + right)/2;

        if(possible(mid, no_of_days, good_days, bad_days))
        {
            right = mid;
        }
        else
        {   
            left = mid;
        }
    }

    cout << right << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
