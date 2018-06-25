#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int length, k;
    string S;
    cin >> length >> k >> S;

    const int NO_OF_ALPHABETS = 26;
    vector <int> frequency(NO_OF_ALPHABETS, 0);
    for(int i = 0; i < S.size(); i++)
        frequency[S[i] - 'a']++;

    vector <int> is_allowed(length, true);
    vector <int> banned(NO_OF_ALPHABETS, false);

    for(int alphabet = 0; alphabet < NO_OF_ALPHABETS && k > 0; alphabet++)
    {
        if(frequency[alphabet] <= k)
        {
            banned[alphabet] = true;
            k -= frequency[alphabet];
        }
        else if(frequency[alphabet] > k)
        {
            for(int i = 0; i < length && k > 0; i++)
            {
                if(S[i] == 'a' + alphabet)
                {
                    k--;
                    is_allowed[i] = false;
                }
            }
        }
    }

    for(int i = 0; i < length; i++)
        if(is_allowed[i] && !banned[S[i] - 'a'])
            cout << S[i];

    return 0;
}
