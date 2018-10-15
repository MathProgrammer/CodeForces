#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string S;
    int length;
    cin >> length >> S;

    sort(S, S + length);
    printf("%s\n", S);
    return 0;
}
