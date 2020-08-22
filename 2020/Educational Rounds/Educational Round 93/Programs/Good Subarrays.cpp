#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    string S;
    cin >> S;
    
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        A[i] = S[i - 1] - '0';
    }
    
    vector <long long> sum_till(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        sum_till[i] = sum_till[i - 1] + A[i];
    }
    
    long long no_of_pairs = 0;
    map <long long, int> frequency;
    frequency[0] = 1;
    for(int i = 1; i <= no_of_elements; i++)
    {
        long long value_here = sum_till[i] - i;
        
        no_of_pairs += frequency[value_here];
        
        frequency[value_here]++;
    }
    
    cout << no_of_pairs << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
