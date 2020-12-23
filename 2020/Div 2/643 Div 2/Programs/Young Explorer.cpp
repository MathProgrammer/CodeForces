#include <iostream>
#include <vector>
#include <algorithm>

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
    
    sort(A.begin(), A.end());
    
    vector <int> max_groups(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        max_groups[i] = max_groups[i - 1];
        
        if(i - A[i] >= 0)
        {
            max_groups[i] = max(max_groups[i], 1 + max_groups[i - A[i]]);
        }
    }
    
    cout << max_groups[no_of_elements] << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
