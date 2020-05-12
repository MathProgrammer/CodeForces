#include <iostream>
#include <vector>

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
    
    vector <int> answer_till(no_of_elements + 1, 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        for(int m = i; m <= no_of_elements; m += i)
        {
            if(A[i] < A[m])
            {
                answer_till[m] = max(answer_till[m], answer_till[i] + 1);
                //cout << "Answer " << m << " = " << answer_till[m] << "\n";
            }
        }
    }
    
    int answer = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        answer = max(answer, answer_till[i]);
    }
    
    cout << answer << "\n";
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
