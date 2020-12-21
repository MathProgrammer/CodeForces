#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void solve()
{
    int no_of_elements, no_of_operations;
    cin >> no_of_elements >> no_of_operations;
    
    int maximum_unsorted = 0;
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
        
        if(A[i] != i)
        {
            maximum_unsorted = max(maximum_unsorted, i);
        }
    }
    
    double failure_probability = (maximum_unsorted == 0 ? 0 : 1);
    for(int i = 1; i <= no_of_operations; i++)
    {
        int right;
        double p;
        cin >> right >> p;
        
        if(right >= maximum_unsorted)
        {
            failure_probability *= (1 - p);
        }
    }
    
    double success_probability = 1 - failure_probability;
    cout << fixed << setprecision(6) << success_probability << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
