#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    int length;
    string S;
    cin >> length >> S;

    map <string, int> frequency;
    int max_frequency = 0;
    string answer;

    for(int i = 0; i + 1 < length; i++)
    {
        string two_gram = S.substr(i, 2);
        frequency[two_gram]++;

        if(frequency[two_gram] > max_frequency)
            max_frequency = frequency[two_gram], answer = two_gram;
    }

    cout << answer;
    return 0;
}
