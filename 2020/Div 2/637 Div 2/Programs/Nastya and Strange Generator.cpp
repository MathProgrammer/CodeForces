#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    vector <int> P(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> P[i];
    }
    
    int possible = true;
    for(int i = no_of_elements; i > 1; i--)
    {
        if(P[i - 1] < P[i])
        {
            if(P[i - 1] != P[i] - 1)
            {
                possible = false;
                break;
            }
            
            continue;
        }
    }
    
    cout << (possible ? "Yes\n" : "No\n");
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
