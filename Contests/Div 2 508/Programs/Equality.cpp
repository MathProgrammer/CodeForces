#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int length, no_of_letters;
    string S;
    cin >> length >> no_of_letters >> S;

    vector <int> frequency(no_of_letters, 0);
    for(int i = 0; i < S.size(); i++)
        frequency[S[i] - 'A']++;

    int minimum_frequency = length + 1;
    for(int i = 0; i < no_of_letters; i++)
        minimum_frequency = min(minimum_frequency, frequency[i]);

    int answer = minimum_frequency*no_of_letters;
    cout << answer;

    return 0;
}
