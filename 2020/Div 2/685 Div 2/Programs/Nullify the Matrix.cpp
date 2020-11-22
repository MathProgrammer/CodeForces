#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int rows, columns;
    cin >> rows >> columns;
    
    vector <int> diagonal (rows + columns + 1);
    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= columns; j++)
        {
            int x;
            cin >> x;
            
            diagonal[i + j] ^= x;
        }
    }
    
    int nim_sum = 0;
    for(int i = 2; i <= rows + columns; i++)
    {
        nim_sum += diagonal[i];
    }
    
    cout << (nim_sum != 0 ? "Ashish\n" : "Jeel\n");
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
