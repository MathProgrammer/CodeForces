#include <iostream>
#include <vector>
#include <set>

using namespace std;

int possible(int k, set <int> &S)
{
    for(auto it = S.begin(); it != S.end(); it++)
    {
        int x = *it;
        
        if(S.find(x^k) == S.end())
        {
            return false;
        }
    }
    
    return true;
}

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    vector <int> A(no_of_elements + 1);
    set <int> S;
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
        
        S.insert(A[i]);
    }
    
    const int oo = 1e9, MAX_K = 1025;
    int best_k = oo;
    for(int k = 1; k <= MAX_K; k++)
    {
        if(possible(k, S))
        {
            best_k = min(best_k, k);
            
            break;
        }
    }
    
    if(best_k == oo)
    {
        best_k = -1;
    }
    
    cout << best_k << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
