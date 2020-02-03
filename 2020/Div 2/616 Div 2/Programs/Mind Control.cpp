#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int no_of_elements, position, controlled;
    cin >> no_of_elements >> position >> controlled;
    
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    controlled = min(controlled, position - 1);
    int uncontrolled = (position - 1) - controlled;
    
    int best_answer = 0;
    for(int c = 0; c <= controlled; c++)
    {
        int best_answer_for_c = 1e9 + 5;
        
        for(int i = 0; i <= uncontrolled; i++)
        {
            int prefix = c + i, suffix = no_of_elements - (controlled - c) - (uncontrolled - i) + 1;//Last element is n, not (n - 1) so add +1
            
            int answer_here = max(A[prefix + 1], A[suffix - 1]);
           
            best_answer_for_c = min(answer_here, best_answer_for_c);
        }
        
        best_answer = max(best_answer, best_answer_for_c);
    }
    
    cout << best_answer << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
