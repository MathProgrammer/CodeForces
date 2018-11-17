#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int length;
    string S;
    cin >> length >> S;

    vector <int> is_ignored(length, false);
    for(int i = 0; i < length; i++)
    {
        if(i + 1 == length || S[i] > S[i + 1])
        {
            is_ignored[i] = true;
            break;
        }
    }

    for(int i = 0; i < length; i++)
        if(!is_ignored[i])
            cout << S[i];

    return 0;
}
