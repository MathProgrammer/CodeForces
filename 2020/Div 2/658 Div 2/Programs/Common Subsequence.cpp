#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    
    vector <int> A(n);
    for(int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    
    sort(all(A));
    
    vector <int> B(m);
    for(int i = 0; i < m; i++)
    {
        cin >> B[i];
    }
    
    sort(all(B));
    
    for(int i = 0; i < A.size(); i++)
    {
        if(binary_search(B.begin(), B.end(), A[i]))
        {
            cout << "YES\n";
            
            cout << "1 " << A[i] << "\n";
            
            return;
        }
    }
    
    cout << "NO\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
