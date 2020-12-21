#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int length, palindrome_length;
    cin >> length >> palindrome_length;
    
    vector <char> S(length + 3);
    for(int i = 0; i < palindrome_length; i++)
    {
        S[i] = 'a';
    }
    
    for(int i = palindrome_length; i < length; i += 3)
    {
        S[i] = 'c';
        S[i + 1] = 'b';
        S[i + 2] = 'a';
    }
    
    for(int i = 0; i < length; i++)
    {
        cout << S[i];
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
