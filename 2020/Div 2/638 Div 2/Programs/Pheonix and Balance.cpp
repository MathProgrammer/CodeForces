#include <iostream>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    
    int heavy_pile = (1 << n);
    for(int i = 1; i < n/2; i++)
    {
        heavy_pile += (1 << i);
    }
    
    int light_pile = 0;
    for(int i = n/2; i < n; i++)
    {
        light_pile += (1 << i);
    }
    
    cout << (heavy_pile - light_pile) << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
