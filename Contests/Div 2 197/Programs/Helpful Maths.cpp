#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    string expression;
    cin >> expression;

    typedef unsigned int u_int;
    vector <char> number;
    for(u_int i = 0; i < expression.size(); i++)
    {
        if(expression[i] != '+')
            number.push_back(expression[i]);
    }

    sort(all(number));

    for(u_int i = 0; i < number.size() - 1; i++)
    {
        printf("%c+", number[i]);
    }
    printf("%c\n", number.back());

    return 0;
}
