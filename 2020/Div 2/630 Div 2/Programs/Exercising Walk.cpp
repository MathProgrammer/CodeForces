#include <iostream>

using namespace std;

void solve()
{
    long long up, down, left, right;
    cin >> left >> right >> down >> up;
    
    long long x, y, x1, y1, x2, y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    
    if(x1 == x2)
    {
        if(left + right > 0)
        {
            cout << "NO\n";
            return;
        }
    }
    else
    {
        long long end = x - left + right;
        
        if(end < x1 || x2 < end)
        {
            cout << "NO\n";
            return;
        }
    }
    
    if(y1 == y2)
    {
        if(up + down > 0)
        {
            cout << "NO\n";
            return;
        }
    }
    else
    {
        long long end = y - down + up;
        
        if(end < y1 || y2 < end)
        {
            cout << "NO\n";
            return;
        }
    }
    
    cout << "Yes\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
