#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
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
    
    vector <int> B(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> B[i];
    }
    
    const int oo = 1e9 + 9;
    int target_A = oo, target_B = oo;
    
    for(int i = 1; i <= no_of_elements; i++)
    {
        target_A = min(target_A, A[i]);
        target_B = min(target_B, B[i]);
    }
    
    long long no_of_moves = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        long long a_moves_here = A[i] - target_A, b_moves_here = B[i] - target_B;
        
        no_of_moves += max(a_moves_here, b_moves_here);
    }
    
    cout << no_of_moves << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
