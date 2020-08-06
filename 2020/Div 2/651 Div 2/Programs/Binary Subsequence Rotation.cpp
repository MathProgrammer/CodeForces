#include <iostream>
#include <set>

using namespace std;

int no_of_1s(string S)
{
    int count = 0;
    
    for(int i = 0; i < S.size(); i++)
    {
        count += (S[i] == '1');
    }
    
    return count;
}

int main()
{
    int length;
    string S, T;
    cin >> length >> S >> T;
    
    if(no_of_1s(S) != no_of_1s(T))
    {
        cout << "-1\n";
        
        return 0;
    }
    
    string effective_S;
    for(int i = 0; i < length; i++)
    {
        if(S[i] != T[i])
        {
            effective_S += S[i];
        }
    }
    
    int no_of_sequences = 0;
    set <int> last_sequence[2];
    for(int i = 0; i < effective_S.size(); i++)
    {
        int current = effective_S[i] - '0';
        int complement = 1 - current;
        
        if(last_sequence[complement].size() == 0)
        {
            no_of_sequences++;
            
            last_sequence[current].insert(no_of_sequences);
        }
        else
        {
            auto it = last_sequence[complement].begin();
            
            last_sequence[current].insert(*it);
            
            last_sequence[complement].erase(it);
        }
    }
    
    cout << no_of_sequences << "\n";
    
    return 0;
}
