#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

#define all (v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_words;
    cin >> no_of_words;

    set <string> distinct_words;

    while(no_of_words--)
    {
        string word;
        cin >> word;

        const int NO_OF_ALPHABETS = 26;
        vector <int> present(NO_OF_ALPHABETS, false);

        for(int i = 0; i < word.size(); i++)
            present[word[i] - 'a'] = true;

        string root;
        for(int i = 0; i < NO_OF_ALPHABETS; i++)
            if(present[i])
                root += (char)('a' + i);

        distinct_words.insert(root);
    }

    cout << distinct_words.size();
    return 0;
}
