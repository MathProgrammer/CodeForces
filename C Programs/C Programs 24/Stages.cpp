#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_letters, required_letters;
    string S;
    cin >> no_of_letters >> required_letters >> S;

    const int NO_OF_ALPHABETS = 26;
    vector <int> present(NO_OF_ALPHABETS, false);
    for(int i = 0; i < no_of_letters; i++)
        present[S[i] - 'a'] = true;

    int sum = 0, chosen = 0;
    for(int i = 0; i < NO_OF_ALPHABETS && chosen < required_letters; i++)
    {
        if(present[i])
        {
            chosen++;

            sum += i + 1;
            i++;
        }
    }

    cout << (chosen < required_letters ? -1 : sum);

    return 0;
}

