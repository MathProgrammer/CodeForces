#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int no_of_elements, no_of_days;
    cin >> no_of_elements >> no_of_days;
    
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
        cin >> A[i];
    
    for(int i = 2; i <= no_of_elements && no_of_days > 0; i++)
    {
        while(A[i] > 0 && no_of_days >= (i - 1))
        {
            A[i]--;
            
            A[1]++;
            
            no_of_days -= (i - 1);
        }
    }
    
    cout << A[1] << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
