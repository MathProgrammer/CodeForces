#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    string num_1, num_2, answer;
    cin >> num_1 >> num_2;

    typedef unsigned int u_int;
    for(u_int i = 0; i < num_1.size(); i++)
    {
        answer += (num_1[i] == num_2[i] ? '0' : '1');
    }
    cout << answer;
    return 0;
}
