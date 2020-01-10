#include <iostream>

using namespace std;

void solve()
{
    string word;
    cin >> word;
    
    switch(word[word.size() - 1])
    {
        case 'o': cout << "FILIPINO\n"; return;
        case 'u': cout << "JAPANESE\n"; return;
        case 'a': cout << "KOREAN\n"; return;
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
