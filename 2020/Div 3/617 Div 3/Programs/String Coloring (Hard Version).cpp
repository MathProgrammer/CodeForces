#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int length;
    string S;
    cin >> length >> S;
    
    const int NO_OF_ALPHABETS = 26;
    vector <int> max_till(NO_OF_ALPHABETS);
    vector <int> sequence_no(length, 1);
    
    int no_of_sequences = 0;
    for(int i = 0; i < length; i++)
    {
        for(int alpha = S[i] - 'a' + 1; alpha < NO_OF_ALPHABETS; alpha++)
        {
            sequence_no[i] = max(sequence_no[i], max_till[alpha] + 1);
        }
        
        max_till[S[i] - 'a'] = max(max_till[S[i] - 'a'], sequence_no[i]);
        
        no_of_sequences = max(no_of_sequences, sequence_no[i]);
    }
    
    cout << no_of_sequences << "\n";
    
    for(int i = 0; i < length; i++)
    {
        cout << sequence_no[i] << " ";
    }
    
    cout << "\n";
    
    return 0;
}
