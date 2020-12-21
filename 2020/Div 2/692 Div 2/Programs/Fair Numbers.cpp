#include <iostream>

using namespace std;

int fair(long long n)
{
    long long value = n;
    
    while(n)
    {
        int digit = n%10;
        
        if(digit != 0 && value%digit != 0)
        {//cout << value << " not divisible "
            return false;
        }
        
        n /= 10;
    }
    
    return true;
}

void solve()
{
    long long n;
    cin >> n;
    
    long long answer;
    
    for(answer = n; !fair(answer); answer++);
    
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
