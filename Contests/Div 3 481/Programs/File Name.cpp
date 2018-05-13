#include <iostream>
#include <string>

using namespace std;

int main()
{
    int length;
    string S;
    cin >> length >> S;

    int removable_characters = 0;
    for(int i = 2; i < length; i++)
       removable_characters += (S[i] == 'x' && S[i - 1] == 'x' && S[i - 2] == 'x');

    cout << removable_characters;
    return 0;
}
