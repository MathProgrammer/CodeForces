#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == j)
            {
                cout << "1 ";
            }
            else if(j == (i + 1) || (i == n && j == 1))
            {
                cout << "4 ";
            }
            else
            {
                cout << "0 ";
            }
        }
        
        cout << "\n";
    }
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
