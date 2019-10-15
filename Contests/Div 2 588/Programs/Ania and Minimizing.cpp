#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int length, no_of_steps;
    cin >> length >> no_of_steps;

    string N;
    cin >> N;

    for(int i = 0; i < length && no_of_steps > 0; i++)
    {
        if(i == 0)
        {
            if(length == 1)
            {
                if(N[i] != '0')
                {
                    N[i] = '0';
                    no_of_steps--;
                }

                continue;
            }

            if(N[i] != '1')
            {
                N[i] = '1';
                no_of_steps--;
            }

            continue;
        }

        if(N[i] == '0')
        {
            continue;
        }

        N[i] = '0';
        no_of_steps--;
    }

    cout << N << "\n";
    return 0;
}

