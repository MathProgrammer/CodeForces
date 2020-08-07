#include <iostream>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    
    int eights = n/4 + (n%4 != 0);

    int nines = n - eights;
    
    for(int i = 1; i <= nines; i++)
    {
        cout << "9";
    }
    
    for(int i = 1; i <= eights; i++)
    {
        cout << "8";
    }
    
    cout << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
