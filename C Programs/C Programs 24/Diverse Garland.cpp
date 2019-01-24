#include <iostream>
#include <string>

using namespace std;

int main()
{
    int length;
    string S;
    cin >> length >> S;

    string colour = "RGB";
    int replacements = 0;

    for(int i = 1; i < length; i++)
    {
        if(S[i] == S[i - 1])
        {
            for(int j = 0; j < colour.size(); j++)
            {
                if( (i + 1 == length && colour[j] != S[i - 1]) || (colour[j] != S[i + 1] && colour[j] != S[i - 1]) )
                {
                    replacements++;
                    S[i] = colour[j];
                    break;
                }
            }
        }
    }

    cout << replacements << "\n" << S;
    return 0;
}
