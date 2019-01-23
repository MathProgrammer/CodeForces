#include <iostream>
#include <string>

using namespace std;

int replacements(string &R, string &S)
{
    int difference_count = 0;

    for(int i = 0; i < S.size(); i++)
        difference_count += (S[i] != R[i%3]);

    return difference_count;
}

int main()
{
    int length;
    cin >> length;

    string S;
    cin >> S;

    const int NO_OF_OPTIONS = 6, oo = 1e9;

    string option[NO_OF_OPTIONS] = {"RGB", "RBG", "BRG", "BGR", "GRB", "GBR"};

    int minimum_replacement = oo, best_option = 0;

    for(int i = 0; i < NO_OF_OPTIONS; i++)
    {
        int replacements_here = replacements(option[i], S);

        if(replacements_here < minimum_replacement)
        {
            minimum_replacement = replacements_here;
            best_option = i;
        }
    }

    cout << minimum_replacement << "\n";
    for(int i = 0; i < length; i++)
        cout << option[best_option][i%3];

    return 0;
}
