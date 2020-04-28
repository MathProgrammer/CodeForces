#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int no_of_elements, k;
    cin >> no_of_elements >> k;
    
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    vector <int> frequency(2*k + 1, 0);
    for(int i = 1; i <= no_of_elements/2; i++)
    {
        frequency[A[i] + A[no_of_elements - i + 1]]++;
    }
    
    vector <int> lines_starting_at(2*k + 2);
    vector <int> lines_ending_at(2*k + 2);
    for(int i = 1; i <= no_of_elements/2; i++)
    {
        lines_starting_at[min(A[i], A[no_of_elements - i + 1]) + 1]++;
        lines_ending_at[max(A[i], A[no_of_elements - i + 1]) + k + 1]++;
    }
    
    vector <int> lines_passing_through(2*k + 1, 0);
    for(int i = 1; i <= 2*k; i++)
    {
        lines_passing_through[i] = lines_passing_through[i - 1] + lines_starting_at[i] - lines_ending_at[i];
        
        //cout << "L " << i << " = " << lines_passing_through[i] << "\n";
    }
    
    int answer = no_of_elements;
    for(int x = 1; x <= 2*k; x++)
    {
        int changes_1 = lines_passing_through[x] - frequency[x];
        int changes_2 = no_of_elements/2 - changes_1 - frequency[x];
        
        //cout << "Changes 1 = " << changes_1 << " Changes 2 = " << changes_2 << " for " << x << "\n";
        answer = min(answer, changes_1 + 2*changes_2);
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
