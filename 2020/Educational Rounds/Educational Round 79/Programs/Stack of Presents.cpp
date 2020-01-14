#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int stack_presents, sent_presents;
    cin >> stack_presents >> sent_presents;
    
    vector <int> A(stack_presents + 1);
    vector <int> A_index(stack_presents + 1);
    for(int i = 1; i <= stack_presents; i++)
    {
        cin >> A[i];
        
        A_index[A[i]] = i;
    }
    
    vector <int> B(sent_presents + 1);
    for(int i = 1; i <= sent_presents; i++)
    {
        cin >> B[i];
    }
    
    int max_inserted = 0;
    long long total_time = 0;
    for(int i = 1; i <= sent_presents; i++)
    {
        int effective_index = A_index[B[i]] - (i - 1);
        
        if(max_inserted > A_index[B[i]])
        {
            effective_index = 1;
        }
        
        total_time += 2*(effective_index - 1) + 1;
        
        max_inserted = max(max_inserted, A_index[B[i]]);
    }
    
    cout << total_time << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
