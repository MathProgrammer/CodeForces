#include <iostream>

using namespace std;

void solve()
{
    int hours, minutes;
    cin >> hours >> minutes;
    
    const int MAX_HOUR = 23, MAX_MINUTE = 60;
    int remaining_minutes = 60*(MAX_HOUR - hours) + (MAX_MINUTE - minutes);
    
    cout << remaining_minutes << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
