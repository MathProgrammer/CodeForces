#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

void solve()
{
    long long no_of_elements, x;
    cin >> no_of_elements >> x;
    
    vector <long long> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    sort(all(A));
    
    long long sum = 0;
    int answer = 0;
    for(int i = no_of_elements; i >= 1; i--)
    {
        sum += A[i];
        
        if(sum < (answer + 1)*x)
        {
            break;
        }
            
        answer++;
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
