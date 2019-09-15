#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int length;
    string S, T;
    cin >> length >> S >> T;

    const int NO_OF_ALPHABETS = 2, A = 0, B = 1;
    vector <int> frequency(NO_OF_ALPHABETS, 0);
    for(int i = 0; i < S.size(); i++)
    {
        frequency[S[i] - 'a']++;
    }

    for(int i = 0; i < T.size(); i++)
    {
        frequency[T[i] - 'a']++;
    }

    if(frequency[A]%2 == 1 || frequency[B]%2 == 1)
    {
        cout << "-1\n";

        return 0;
    }

    vector <int> ABs;
    for(int i = 0; i < length; i++)
    {
        if(S[i] == 'a' && T[i] == 'b')
        {
            ABs.push_back(i + 1);
        }
    }

    vector <int> BAs;
    for(int i = 0; i < length; i++)
    {
        if(S[i] == 'b' && T[i] == 'a')
        {
            BAs.push_back(i + 1);
        }
    }

    int no_of_operations = 0;

    if(ABs.size()%2 == 1 && BAs.size()%2 == 1)
    {
        no_of_operations = ABs.size()/2 + BAs.size()/2 + 2;
    }
    else if(ABs.size()%2 == 0 && BAs.size()%2 == 0)
    {
        no_of_operations = ABs.size()/2 + BAs.size()/2;
    }
    else //Redundant but just to be safe
    {
        cout << "-1\n";

        return 0;
    }

    cout << no_of_operations << "\n";
    for(int i = 0; i + 1 < ABs.size(); i += 2)
    {
        cout << ABs[i] << " " << ABs[i + 1] << "\n";
    }

    for(int i = 0; i + 1 < BAs.size(); i += 2)
    {
        cout << BAs[i] << " " << BAs[i + 1] << "\n";
    }

    if(ABs.size()%2 == 1 && BAs.size()%2 == 1)
    {
        int last_AB = ABs.size() - 1, last_BA = BAs.size() - 1;

        cout << ABs[last_AB] << " " << ABs[last_AB] << "\n";
        cout << ABs[last_AB] << " " << BAs[last_BA] << "\n";
    }

    return 0;
}
