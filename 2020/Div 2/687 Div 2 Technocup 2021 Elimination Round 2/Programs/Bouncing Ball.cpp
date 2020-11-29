#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int no_of_elements, p, k;
    cin >> no_of_elements >> p >> k;
    
    string S;
    cin >> S;
    
    int add_cost, removal_cost;
    cin >> add_cost >> removal_cost;
    
    vector <long long> sum(S.size() + k + 1, 0);
    for(int i = S.size() - 1; i >= 0; i--)
    {
        sum[i] = add_cost*(S[i] == '0') + sum[i + k];
        
        //cout << "Sum " << i << " = " << sum[i] << "\n";
    }
    
    const long long oo = 1e18;
    long long answer = oo;
    
    for(int i = p - 1, j = S.size(), r = 0; j >= p && i < S.size(); i++, j--, r++)
    {
        answer = min(answer, (r)*removal_cost + sum[i]);
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
