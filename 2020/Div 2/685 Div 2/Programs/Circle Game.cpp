#include <iostream>

using namespace std;

long long ceil(long long n, long long d)
{
    return (n/d) + (n%d != 0);
}

long long square(long long n)
{
    return n*n;
}

void solve()
{
    long long d, k;
    cin >> d >> k;
    
    long long left = 0, right = ceil(d, k);
    while(right - left > 1)
    {
        long long mid = (left + right)/2;
        
        if(2*square(k*mid) <= square(d))
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }
    
    long long z = left;
    
    cout << (square(k*z) + square(k*(z + 1)) <= square(d) ? "Ashish" : "Utkarsh") << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
