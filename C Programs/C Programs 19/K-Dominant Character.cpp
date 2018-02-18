#include <iostream>
#include <string>

using namespace std;

int main()
{
    string S;
    cin >> S;

    const int NO_OF_LETTERS = 26;
    int length = S.size(), answer = S.size();

    for(int alphabet = 0; alphabet < NO_OF_LETTERS; alphabet++)
    {
        int last_occurence = -1, largest_gap_for_this_alphabet = 0;

        for(int i = 0; S[i] != '\0'; i++)
        {
            if(S[i] == 'a' + alphabet)
            {
                largest_gap_for_this_alphabet = max(largest_gap_for_this_alphabet, i - last_occurence);
                last_occurence = i;
            }
        }

        largest_gap_for_this_alphabet = max(largest_gap_for_this_alphabet, length - last_occurence);

        answer = min(answer, largest_gap_for_this_alphabet);
    }

    cout << answer;
    return 0;
}
