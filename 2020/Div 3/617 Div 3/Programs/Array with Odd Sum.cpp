#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    int odd_count = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        int x;
        cin >> x;
        
        odd_count += (x%2 == 1);
    }
    
    cout << ((odd_count%2 == 1) || (odd_count > 0 && odd_count%2 == 0 && odd_count != no_of_elements) ? "YES\n" : "NO\n");
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
