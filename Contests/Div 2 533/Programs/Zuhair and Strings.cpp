#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int length, k;
    cin >> length >> k;

    string S;
    cin >> S;

    vector <int> longest_block_till(length, 0);
    longest_block_till[0] = 1;
    for(int i = 1; i < length; i++)
    {
        longest_block_till[i] = (S[i] == S[i - 1] ? longest_block_till[i - 1] + 1 : 1);
    }

    const int NO_OF_ALPHABETS = 26;
    vector <int> no_of_k_sequences(NO_OF_ALPHABETS, 0);
    for(int i = 0; i < length; i++)
    {
        if(i == length - 1 || S[i] != S[i + 1])//Reached the end of a block
        {
            no_of_k_sequences[S[i] - 'a'] += longest_block_till[i]/k;
        }
    }

    int answer = 0;
    for(int i = 0; i < NO_OF_ALPHABETS; i++)
        answer = max(answer, no_of_k_sequences[i]);

    cout << answer;
    return 0;
}
