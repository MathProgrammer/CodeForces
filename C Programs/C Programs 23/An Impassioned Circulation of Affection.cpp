#include <iostream>
#include <string>

const int MAX_ALPHABETS = 26, MAX_N = 1505;
int maximum_segment[MAX_ALPHABETS][MAX_N];

using namespace std;

int main()
{
    int length;
    string S;
    cin >> length >> S;

    for(int ch = 0; ch < MAX_ALPHABETS; ch++)
    {
        for(int left = 0; left < length; left++)
        {
            int replacements = 0;

            for(int right = left; right < length; right++)
            {
                replacements += (S[right] != 'a' + ch);

                maximum_segment[ch][replacements] = max(maximum_segment[ch][replacements], right - left + 1);
            }
        }
    }

    for(int ch = 0; ch < MAX_ALPHABETS; ch++)
    {
        for(int replacements = 1; replacements <= length; replacements++)
        {
            maximum_segment[ch][replacements] = max(maximum_segment[ch][replacements], maximum_segment[ch][replacements - 1]);
        }
    }

    int no_of_queries;
    cin >> no_of_queries;

    while(no_of_queries--)
    {
        int max_replacements;
        char character;

        cin >> max_replacements >> character;
        cout << maximum_segment[character - 'a'][max_replacements] << '\n';
    }

    return 0;
}
