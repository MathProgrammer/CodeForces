#include <iostream>
#include <string>

using namespace std;

int main()
{
    int ones, zeroes, differences;
    cin >> zeroes >> ones >> differences;

    string answer;

    if(ones > zeroes)
    {
        answer += '1';
        ones--;
    }
    else
    {
        answer += '0';
        zeroes--;
    }

    for(int i = 1; i <= differences; i++)
    {
        int len = answer.size();

        if(answer[len - 1] == '0')
        {
            answer += '1';
            ones--;
        }
        else
        {
            answer += '0';
            zeroes--;
        }
    }

    string S;
    for(int i = 0; i < answer.size(); i++)
    {
        S += answer[i];

        if(answer[i] == '1' && ones > 0)
        {
            while(ones--)
                S += '1';
        }

        if(answer[i] == '0' && zeroes > 0)
        {
            while(zeroes--)
                S += '0';
        }
    }

    cout << S;
    return 0;
}
