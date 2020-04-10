#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    vector <int> P(no_of_elements + 1);
    vector <int> C(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> P[i] >> C[i];
    }
    
    int possible = true;
    for(int i = 1; i <= no_of_elements; i++)
    {
        if(P[i - 1] > P[i] || C[i - 1] > C[i])
        {
            possible = false;
        }
        
        if(C[i] - C[i - 1] > P[i] - P[i - 1])
        {
            possible = false;
        }
    }
    
    cout << (possible ? "YES\n" : "NO\n");
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
