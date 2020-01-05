#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int length;
    string S;
    cin >> length >> S;
    
    const int oo = 1e7;
    vector <int> nearest_a(length + 1, oo);
    nearest_a[0] = (S[0] == 'A' ? 0 : oo);
    
    for(int i = 1; i < length; i++)
    {
        nearest_a[i] = (S[i] == 'A' ? 0 : nearest_a[i - 1] + 1);
    }
    
    int answer = 0;
    for(int i = 0; i < length; i++)
    {
        //Skip the prefix
        if(nearest_a[i] >= oo)
        {
            continue;
        }
        
        answer = max(answer, nearest_a[i]);
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
