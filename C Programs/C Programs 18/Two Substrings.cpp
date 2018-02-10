#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string A;
    cin >> A;

    vector <int> ab;
    vector <int> ba;

    for(int i = 0; i < A.size() - 1; i++)
    {
        if(A[i] == 'A' && A[i + 1] == 'B')
            ab.push_back(i);

        if(A[i] == 'B' && A[i + 1] == 'A')
            ba.push_back(i);
    }

    if(ab.size() == 0 || ba.size() == 0 || !(ab[0] + 1 < ba.back() || ba[0] + 1 < ab.back()))
       cout << "NO\n";
    else
        cout << "YES\n";
    return 0;
}

