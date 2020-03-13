#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

void solve()
{
    int no_of_columns;
    cin >> no_of_columns;
    
    const int MAX_HEIGHT = 105;
    vector <int> frequency(2, 0);
    vector <int> height(no_of_columns + 1);
    for(int i = 1; i <= no_of_columns; i++)
    {
        cin >> height[i];
        
        frequency[height[i]%2]++;
    }
    
    cout << (frequency[0] == 0 || frequency[1] == 0 ? "YES\n" : "NO\n");
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
