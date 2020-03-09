#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    vector <int> odd;
    vector <int> even;
    for(int i = 1; i <= no_of_elements; i++)
    {
        int x;
        cin >> x;
        
        if(x%2 == 1)
        {
            odd.push_back(i);
        }
        else
        {
            even.push_back(i);
        }
    }
    
    if(odd.size() >= 2)
    {
        cout << "2\n";
        cout << odd[0] << " " << odd[1] << "\n";
        
        return;
    }
    
    if(even.size() >= 1)
    {
        cout << "1\n";
        cout << even[0] << "\n";
        
        return;
    }
    
    cout << "-1\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
