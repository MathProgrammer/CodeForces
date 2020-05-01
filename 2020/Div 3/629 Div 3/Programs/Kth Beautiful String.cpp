#include <iostream>

using namespace std;

void solve()
{
    int length, k;
    cin >> length >> k;
    
    int position_1 = 0, position_2 = 0;
    int string_position = 0;
    for(int i = 2; i <= length; i++)
    {
        string_position += (i - 1);
        if(string_position >= k)
        {
            position_1 = i;
            break;
        }
    }
    
    position_2 = position_1 - (string_position - k) - 1;
    
    for(int i = length; i >= 1; i--)
    {
        cout << (i == position_1 || i == position_2 ? 'b' : 'a');
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
