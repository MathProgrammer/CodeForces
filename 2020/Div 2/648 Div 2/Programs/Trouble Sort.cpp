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
    
    vector <int> present(2, false);
    vector <int> B(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> B[i];
        
        present[B[i]] = true;
    }
    
    int sorted = true;
    for(int i = 1; i < no_of_elements; i++)
    {
        if(A[i] > A[i + 1])
        {
            sorted = false;
        }
    }
    
    cout << (sorted || (present[0] && present[1])? "Yes\n" : "No\n");
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
