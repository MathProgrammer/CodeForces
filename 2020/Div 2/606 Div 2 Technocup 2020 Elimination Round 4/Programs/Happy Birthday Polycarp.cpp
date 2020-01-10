#include <iostream>

using namespace std;

int no_of_digits(int n)
{
    int digits = 0;
    
    while(n > 0)
    {
        n /= 10;
        digits++;
    }
    
    return digits;
}

void solve()
{
    int n;
    cin >> n;
    
    int answer = 9*(no_of_digits(n) - 1);
    
    for(int i = 1, x = 0; i <= 9; i++)
    {
        x = 0;
        
        for(int d = 1; d <= no_of_digits(n); d++)
        {
            x = x*10 + i;
        }
        
        if(x > n)
        {
            break;
        }
        
        answer++;
    }
    
    cout << answer << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
