#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

string solve(string S)
{
    vector <char> digits;
    for(int i = 0; i < S.size(); i++)
        digits.push_back(S[i]);

    sort(all(digits));

    if(digits[0] == '0' && digits.size() > 1)
    {
        int first_nonzero = 1;
        while(digits[first_nonzero] == '0')
            first_nonzero++;

        swap(digits[0], digits[first_nonzero]);
    }

    string answer;
    for(int i = 0; i < digits.size(); i++)
        answer += digits[i];

    return answer;
}

int main()
{
    string A, B;
    cin >> A >> B;

    string answer = solve(A);

    cout << ((answer == B) ? "OK\n" : "WRONG_ANSWER\n");
    return 0;
}
