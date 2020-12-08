#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int no_of_elements, target_sum;
    cin >> no_of_elements >> target_sum;
    
    int sum = 0;
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
        
        sum += A[i];
    }
    
    cout << (sum == target_sum ? "YES" : "NO") << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
