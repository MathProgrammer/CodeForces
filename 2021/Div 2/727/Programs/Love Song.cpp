#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int length, no_of_queries;
    string S;
    cin >> length >> no_of_queries >> S;

    const int NO_OF_ALPHABETS = 26;
    vector <vector <int> > frequency(NO_OF_ALPHABETS, vector <int> (length + 1, 0));
    for(int i = 1; i <= length; i++)
    {
        for(int alpha = 0; alpha < NO_OF_ALPHABETS; alpha++)
        {
            frequency[alpha][i] = frequency[alpha][i - 1];
        }
        frequency[S[i - 1] - 'a'][i]++;
    }

    for(int i = 1; i <= no_of_queries; i++)
    {
        int left, right;
        cin >> left >> right;

        long long length = 0;
        for(int alpha = 0; alpha < NO_OF_ALPHABETS; alpha++)
        {
            long long frequency_here = frequency[alpha][right] - frequency[alpha][left - 1];

            length += (alpha + 1)*frequency_here;
        }

        cout << length << "\n";
    }

    return 0;
}
