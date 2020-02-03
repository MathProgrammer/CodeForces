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
    
    vector <int> prefix_possible(no_of_elements + 1, false);
    for(int i = 1; i <= no_of_elements; i++)
    {
        if(A[i] < i - 1)
        {
            break;
        }
        
        prefix_possible[i] = true;
    }
    
    vector <int> suffix_possible(no_of_elements + 1, false);
    for(int i = no_of_elements; i >= 1; i--)
    {
        if(A[i] < (no_of_elements - i))
        {
            break;
        }
        
        suffix_possible[i] = true;
    }
    
    int possible = (no_of_elements == 1 ? true : false);
    
    for(int i = 1; i <= no_of_elements; i++)
    {
        if(i == 1)
        {
            if(A[i] >= (no_of_elements - i) && suffix_possible[i + 1])
            {
                possible = true;
                break;
            }
        }
        
        if(i == no_of_elements)
        {
            if(A[i] >= (i - 1) && prefix_possible[i - 1])
            {
                possible = true;
                break;
            }
        }
        
        if(A[i] >= (i - 1) && prefix_possible[i - 1] && A[i] >= (no_of_elements - i) && suffix_possible[i + 1])
        {
            possible = true;
            break;
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
