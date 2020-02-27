#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    vector <int> B(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> B[i];
    }
    
    set <int> available;
    for(int i = 1; i <= 2*no_of_elements; i++)
    {
        available.insert(i);
    }
    
    for(int i = 1; i <= no_of_elements; i++)
    {
        available.erase(B[i]);
    }
    
    int possible = true;
    
    vector <int> A(2*no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        auto it = available.lower_bound(B[i]);
        
        if(it == available.end())
        {
            possible = false;
            break;
        }
        
        A[2*i - 1] = B[i];
        A[2*i] = *(it);
        
        available.erase(it);
    }
    
    if(!possible)
    {
        cout << "-1\n";
        
        return;
    }
    
    for(int i = 1; i <= 2*no_of_elements; i++)
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
