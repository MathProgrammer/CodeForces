#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int no_of_elements;
    cin >> no_of_elements;
    
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    const int MAX = 1e6 + 5;
    vector <vector <int> > divisors(MAX);
    for(int i = 1; i < MAX; i++)
    {
        for(int multiple = i; multiple < MAX; multiple += i)
        {
            divisors[multiple].push_back(i);
        }
    }
    
    const int MOD = 1e9 + 7;
    vector <long long> no_of_sequences(MAX, 0), sequences_here(MAX, 0);
    long long total_sequences = 0;
    
    no_of_sequences[0] = 1;
    
    for(int i = 1; i <= no_of_elements; i++)
    {
        for(int d = 0; d < divisors[A[i]].size(); d++)
        {
            int m = divisors[A[i]][d];
            
            sequences_here[m] = no_of_sequences[m - 1];
        }
        
        for(int d = 0; d < divisors[A[i]].size(); d++)
        {
            int m = divisors[A[i]][d];
            
            no_of_sequences[m] += sequences_here[m];
            
            no_of_sequences[m] %= MOD;
        }
    }
    
    for(int i = 1; i < MAX; i++)
    {
        total_sequences += no_of_sequences[i];
        
        total_sequences %= MOD;
    }
    
    cout << total_sequences << "\n";
    return 0;
}
