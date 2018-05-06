#include <iostream>
#include <set>

using namespace std;

int main()
{
    int no_of_words;
    cin >> no_of_words;

    set <int> mask;

    while(no_of_words--)
    {
        string word;
        cin >> word;

        int current_mask = 0;

        for(int i = 0; i < word.size(); i++)
            current_mask |= (1 << (word[i] - 'a'));

        mask.insert(current_mask);
    }

    cout << mask.size();
    return 0;
}
