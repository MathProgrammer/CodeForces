#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int length, distinct_letters;
    scanf("%d %d", &length, &distinct_letters);

    if(length < distinct_letters || (length > 1 && distinct_letters == 1))
    {
        printf("-1\n");
        return 0;
    }

    string answer;
    for(int i = 0; i < length; i++)
        answer += ('a' + i%2);

    for(int i = length - 1, letter = distinct_letters - 1; letter >= 2; i--, letter--)
        answer[i] = ('a' + letter);

    cout << answer;
    return 0;
}
