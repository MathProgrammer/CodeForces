#include <iostream>
#include <string>

using namespace std;

int main()
{
    int k;
    string input;
    cin >> k >> input;

    const int NO_OF_ALPHABETS = 26;
    int frequency[NO_OF_ALPHABETS] = {0};

    for(int i = 0; i < input.length(); i++)
        frequency[input[i] - 'a']++;

    for(int i = 0; i < NO_OF_ALPHABETS; i++)
        if(frequency[i]%k != 0)
        {
            cout << "-1";
            return 0;
        }

    string smaller_string;
    for(int i = 0; i < NO_OF_ALPHABETS; i++)
    {
        for(int j = 0; j < frequency[i]/k; j++)
            smaller_string += ('a' + i);
    }

    for(int i = 1; i <= k; i++)
        cout << smaller_string;
    return 0;
}
