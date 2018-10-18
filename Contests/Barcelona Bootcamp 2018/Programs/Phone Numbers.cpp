#include <iostream>
#include <string>

#define min(a, b) (a < b ? a : b)
using namespace std;

int main()
{
    int length;
    string S;
    cin >> length >> S;

    int no_of_8 = 0;
    for(int i = 0; i < length; i++)
        no_of_8 += (S[i] == '8');

    cout << min(no_of_8, length/11) << endl;
    return 0;
}
