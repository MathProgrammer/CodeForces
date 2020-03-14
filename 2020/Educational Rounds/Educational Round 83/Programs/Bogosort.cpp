#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define all(v) (v).begin() + 1, (v).end()
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
    
    sort(all(A));
    reverse(all(A));
    
    for(int i = 1; i <= no_of_elements; i++)
    {
        cout << A[i] << " ";
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
