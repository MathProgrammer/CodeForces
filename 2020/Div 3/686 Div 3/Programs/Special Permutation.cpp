#include <iostream>

using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    for(int i = 1; i <= no_of_elements; i++)
    {
        cout << i%no_of_elements + 1 << " ";
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
