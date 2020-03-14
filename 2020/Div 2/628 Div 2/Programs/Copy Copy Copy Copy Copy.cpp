#include <iostream>
#include <vector>
#include <set>

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
    
    set <int> distinct;
    for(int i = 1; i <= no_of_elements; i++)
    {
        distinct.insert(A[i]);
    }
    
    cout << distinct.size() << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
