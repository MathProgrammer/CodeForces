#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    vector <int> A(no_of_elements + 1), B(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> B[i];
    }
    
    int positive = false, negative = false, possible = true;;
    for(int i = 1; i <= no_of_elements; i++)
    {
        if(A[i] < B[i])
        {
            if(!positive)
            {
                possible = false;
            }
        }
        
        if(A[i] > B[i])
        {
            if(!negative)
            {
                possible = false;
            }
        }
        
        if(A[i] == 1)
        {
            positive = true;
        }
        
        if(A[i] == -1)
        {
            negative = true;
        }
    }
    
    cout << (possible ? "YES\n" : "NO\n");
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while (no_of_test_cases--)
        solve();
    
    return 0;
}

