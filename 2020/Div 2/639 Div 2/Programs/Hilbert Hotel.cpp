#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    vector <int> A(no_of_elements);
    for(int i = 0; i < no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    vector <int> frequency_mod(no_of_elements);
    for(int i = 0; i < no_of_elements; i++)
    {
        A[i] %= no_of_elements;
        
        if(A[i] < 0)
        {
            A[i] += 2*no_of_elements;
        
            A[i] %= no_of_elements;
        }
        
        frequency_mod[ (i + A[i])%no_of_elements ]++;
    }
    
    int all_unique = true;
    for(int i = 0; i < no_of_elements; i++)
    {
        if(frequency_mod[i] != 1)
        {
            all_unique = false;
        }
    }
    
    cout << (all_unique ? "YES\n" : "NO\n");
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
