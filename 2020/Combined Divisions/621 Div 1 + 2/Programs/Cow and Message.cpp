#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    string S;
    cin >> S;
    
    const int NO_OF_ALPHABETS = 26;
    vector <long long> frequency(NO_OF_ALPHABETS, 0);
    map <string, long long> pair_frequency;
    
    for(int i = S.size() - 1; i >= 0; i--)
    {
        for(int alpha = 0; alpha < NO_OF_ALPHABETS; alpha++)
        {
            char second_letter = (char)('a' + alpha);
            
            string current_pair;
            
            current_pair += S[i];
            
            current_pair += second_letter;
            
            pair_frequency[current_pair] += frequency[alpha];
            
            //cout << "Pair = " << current_pair << " Second Frequency = " << frequency[alpha] << "\n";
        }
        
        frequency[S[i] - 'a']++;
    }
    
    long long answer = 0;
    for(auto it = pair_frequency.begin(); it != pair_frequency.end(); it++)
    {
        answer = max(answer, it->second);
    }
    
    for(int alpha = 0; alpha < NO_OF_ALPHABETS; alpha++)
    {
        answer = max(answer, frequency[alpha]);
    }
    
    cout << answer << "\n";
    return 0;
}
