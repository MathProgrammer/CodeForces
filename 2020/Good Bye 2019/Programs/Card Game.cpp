#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int no_of_elements, a_cards, b_cards;
    cin >> no_of_elements >> a_cards >> b_cards;
    
    int a_max = 0;
    for(int i = 1; i <= a_cards; i++)
    {
        int x;
        cin >> x;
        a_max = max(a_max, x);
    }
    
    int b_max = 0;
    for(int i = 1; i <= b_cards; i++)
    {
        int x;
        cin >> x;
        b_max = max(b_max, x);
    }
    
    cout << (a_max > b_max ? "YES\n" : "NO\n");
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
