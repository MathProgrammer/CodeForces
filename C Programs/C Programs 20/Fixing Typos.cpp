#include <iostream>
#include <string>

using namespace std;

int main()
{
    string A;
    cin >> A;

    string answer;

    for(int i = 0; i < A.size(); i++)
    {
        char last_character, second_last_character, third_last_character;

        if(answer.size() >= 1) last_character = answer[answer.size() - 1];
        if(answer.size() >= 2) second_last_character = answer[answer.size() - 2];
        if(answer.size() >= 3) third_last_character = answer[answer.size() - 3];

        if(answer.size() >= 2 && A[i] == last_character && last_character == second_last_character)
            continue;

        if(answer.size() >= 3 && A[i] == last_character && second_last_character == third_last_character)
            continue;

        answer += A[i];
    }

    cout << answer;
    return 0;
}
