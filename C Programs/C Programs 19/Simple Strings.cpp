#include <iostream>
#include <string>

using namespace std;

char some_char_other_than(char a, char b)
{
    for(char ch = 'a'; ch <= 'z' ; ch++)
        if(ch != a && ch != b)
            return ch;
}

int main()
{
    string A;
    cin >> A;

    string answer;
    answer += A[0];

    for(int i = 1; i < A.size(); i++)
    {
        char predecessor = answer[answer.size() - 1];
        char successor = (i + 1 == A.size() ? predecessor : A[i + 1]);

        if(A[i] == predecessor)
        {
            answer += some_char_other_than(predecessor, successor);
        }
        else
        {
            answer += A[i];
        }
    }

    cout << answer;
    return 0;
}
