#include <iostream>
#include <vector>
#include <map>

using namespace std;

int ceil(int n, int d)
{
    return (n/d) + (n%d != 0);
}

int calculate(vector <int> &A, int k, int chosen)
{
    int n = A.size() - 1, no_of_days = 0;
    
    for(int i = 1; i <= n; i++)
    {
        if(A[i] != chosen)
        {
            no_of_days++;
            
            i += (k - 1);
        }
    }
    
    return no_of_days;
}

void solve()
{
    int no_of_elements, k;
    cin >> no_of_elements >> k;
    
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
   
    const int MAX_COLOURS = 100;
    int answer = ceil(no_of_elements, k);
    for(int c = 1; c <= MAX_COLOURS; c++)
    {
        answer = min(answer, calculate(A, k, c));
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
