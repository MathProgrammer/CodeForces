#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    vector <long long> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    int is_zero = false;
    vector <long long> prefix_sum(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        prefix_sum[i] = A[i] + prefix_sum[i - 1];
        
        if(prefix_sum[i] == 0)
        {
            is_zero = true;
        }
    }
    
    long long best_choice = -1e10;
    vector <long long> max_sum(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        max_sum[i] = max(A[i], A[i] + max_sum[i - 1]);
       
        if(i == no_of_elements && max_sum[i] == prefix_sum[i] && is_zero == false)
        {
            continue;
        }
            
        best_choice = max(best_choice, max_sum[i]);
    }
    
    cout << (prefix_sum[no_of_elements] > best_choice  ? "YES\n" : "NO\n");
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
