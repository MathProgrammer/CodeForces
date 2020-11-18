#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin() + 1, (v).end()

using namespace std;

void solve()
{
    int no_of_elements, no_of_arrays;
    cin >> no_of_elements >> no_of_arrays;
    
    vector <int> A(no_of_elements*no_of_arrays + 1);
    for(int i = 1; i <= no_of_elements*no_of_arrays; i++)
    {
        cin >> A[i];
    }
    
    int median_position = (no_of_elements/2) + (no_of_elements%2);
    int suffix = no_of_elements - median_position;
    
    sort(all(A));
    reverse(all(A));
    
    long long answer = 0;
    for(int i = suffix + 1, medians = 0; medians < no_of_arrays; i += (suffix + 1))
    {
        
            answer += A[i];
            
            medians++;
        
    }
    
    cout << answer << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
