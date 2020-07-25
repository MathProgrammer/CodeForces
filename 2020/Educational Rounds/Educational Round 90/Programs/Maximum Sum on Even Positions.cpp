#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    vector <long long> A(no_of_elements + 1);
    for(int i = 0; i < no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    long long sum = 0;
    for(int i = 0; i < no_of_elements; i += 2)
    {
        sum += A[i];
    }
    
    vector <long long> max_changes_here(no_of_elements + 1);
    for(int i = 1; i < no_of_elements; i++)
    {
        if(i == 1)
        {
            max_changes_here[i] = A[i] - A[i - 1];
            
            continue;
        }
        
        if(i%2 == 1)
        {
            max_changes_here[i] = max(A[i] - A[i - 1], A[i] - A[i - 1] + max_changes_here[i - 2]);
        }
        else
        {
            max_changes_here[i] = max(-A[i] + A[i - 1], -A[i] + A[i - 1] + max_changes_here[i - 2]);
        }
    }
    
    long long max_changes = 0;
    for(int i = 0; i < no_of_elements; i++)
    {
        max_changes = max(max_changes, max_changes_here[i]);
    }
    
    sum += max_changes;
    
    cout << sum << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
