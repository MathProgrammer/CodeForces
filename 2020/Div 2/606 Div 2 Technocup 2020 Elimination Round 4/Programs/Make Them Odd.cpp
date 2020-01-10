#include <iostream>
#include <vector>
#include <set>

using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    set <int> S;
    for(int i = 1; i <= no_of_elements; i++)
    {
        int x;
        cin >> x;
        
        if(x%2 == 0)
        {
            S.insert(x);
        }
    }
    
    int no_of_steps = 0;
    while(!S.empty())
    {
        int maximum = *(S.rbegin());
        
        while(maximum%2 == 0)
        {
            if(S.find(maximum) != S.end())
            {
                S.erase(S.find(maximum));
            }
            
            maximum /= 2;
            
            no_of_steps++;
        }
    }
    
    cout << no_of_steps << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
