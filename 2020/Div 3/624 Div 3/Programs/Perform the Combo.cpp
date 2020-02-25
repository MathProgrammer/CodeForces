#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

void solve()
{
    int length, no_of_tries;
    cin >> length >> no_of_tries;
    
    string S;
    cin >> S;
    
    vector <int> P(no_of_tries + 1);
    for(int i = 1; i <= no_of_tries; i++)
    {
        cin >> P[i];
    }
    
    const int NO_OF_ALPHABETS = 26;
    vector <long long> no_of_hits(NO_OF_ALPHABETS, 0);
    vector <long long> frequency(NO_OF_ALPHABETS, 0);
    
    sort(all(P));
    vector <long long> no_of_mistakes_here(length + 1, 0);
    for(int i = 1; i <= no_of_tries; i++)
    {
        no_of_mistakes_here[P[i] - 1]++;
    }
    no_of_mistakes_here[length - 1] = 1;
    
    for(int i = 0, j = 1; i < length; i++)
    {
        frequency[S[i] - 'a']++;
        
        if( (j <= no_of_tries && i + 1 == P[j]) || i + 1 == length)
        {
            for(int alpha = 0; alpha < NO_OF_ALPHABETS; alpha++)
            {
                no_of_hits[alpha] += no_of_mistakes_here[i]*frequency[alpha];
                //cout << "F" << alpha << " = " << no_of_hits[alpha] << "\n";
            }
            
            while(j <= no_of_tries && i + 1 == P[j])
            {
                j++;
            }
        }
    }
    
    for(int alpha = 0; alpha < NO_OF_ALPHABETS; alpha++)
    {
        cout << no_of_hits[alpha] << " ";
    }
    
    cout << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
