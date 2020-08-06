#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define all(v) (v).begin(), (v).end()
using namespace std;

void solve()
{
    int length;
    string S;
    cin >> length >> S;
    
    vector <int> sequence_no(length + 1);
    set <int> available_label[2];
    
    int no_of_sequences = 1;
    available_label[0].insert(1);
    available_label[1].insert(1);
    
    for(int i = 0; i < length; i++)
    {
        int current = S[i] - '0';
        int complement = 1 - current;
        
        if(available_label[complement].size() == 0)
        {
            no_of_sequences++;
            
            sequence_no[i] = no_of_sequences;
            
            available_label[current].insert(sequence_no[i]);
        }
        else
        {
            auto it = available_label[complement].begin();
            
            sequence_no[i] = *it;
            
            available_label[current].insert(sequence_no[i]);
            
            available_label[complement].erase(sequence_no[i]);
        }
    }
    
    cout << no_of_sequences << "\n";
    
    for(int i = 0; i < length; i++)
    {
        cout << sequence_no[i] << " ";
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
