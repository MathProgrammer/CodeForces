#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    int length_of_sentence, no_of_words;
    cin >> length_of_sentence >> no_of_words;

    map <string, string> translated;

    for(int i = 1; i <= no_of_words; i++)
    {
        string word, translation;
        cin >> word >> translation;

        translated[word] = translation;
    }

    for(int i = 1; i <= length_of_sentence; i++)
    {
        string current_word;
        cin >> current_word;

        cout << (current_word.length() <= translated[current_word].length() ? current_word : translated[current_word]) << " ";
    }
    return 0;
}
