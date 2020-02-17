#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
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
    
    vector <long long> fixed;
    
    for(int i = 2; i <= no_of_elements; i++)
    {
        if(A[i - 1] == -1 && A[i] != -1)
        {
            fixed.push_back(A[i]);
        }
    }
    
    for(int i = 1; i < no_of_elements; i++)
    {
        if(A[i + 1] == -1 && A[i] != -1)
        {
            fixed.push_back(A[i]);
        }
    }
    
    sort(all(fixed));
    
    long long mid;
    
    if(fixed.size() == 0)
    {
        mid = 0;
    }
    else
    {
        mid = (fixed[0] + fixed.back())/2;
    }
    
    for(int i = 1; i <= no_of_elements; i++)
    {
        if(A[i] == -1)
        {
            A[i] = mid;
        }
    }
    
    long long m = 0;
    for(int i = 2; i <= no_of_elements; i++)
    {
        m = max(m, abs(A[i] - A[i - 1]));
    }
    
    cout << m << " " << mid << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
