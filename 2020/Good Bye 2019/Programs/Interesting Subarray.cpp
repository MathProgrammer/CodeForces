#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    for(int i = 1; i < no_of_elements; i++)
    {
        if(abs(A[i + 1] - A[i]) >= 2)
        {
            cout << "YES\n";
            cout << i << " " << i + 1 << "\n";
            
            return;
        }
    }

    cout << "NO\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
