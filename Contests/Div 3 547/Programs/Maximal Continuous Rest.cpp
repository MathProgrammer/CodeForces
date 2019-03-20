#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int length;
    cin >> length;

    vector <int> A(length + 1);
    for(int i = 1; i <= length; i++)
        cin >> A[i];

    int maximum_1s_till_here = 0, maximum_1s = 0;
    for(int i = 1; i <= length; i++)
    {
        maximum_1s_till_here = (A[i] == 1 ? maximum_1s_till_here + 1 : 0);

        maximum_1s = max(maximum_1s, maximum_1s_till_here);
    }

    int prefix = 0;
    for(int i = 1; i <= length; i++)
    {
        if(A[i] != 1)
            break;

        prefix++;
    }

    int suffix = 0;
    for(int i = length; i >= 1; i--)
    {
        if(A[i] != 1)
            break;

        suffix++;
    }

    maximum_1s = max(maximum_1s, prefix + suffix);
    maximum_1s = min(maximum_1s, length);

    cout << maximum_1s;
    return 0;
}
