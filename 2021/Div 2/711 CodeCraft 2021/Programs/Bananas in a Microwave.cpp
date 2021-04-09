#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e5, ADD = 1, MULTIPLY = 2;

long long ceil(long long n, long long d)
{
    return (n/d) + (n%d != 0);
}

long long operate(int type, long long b, long long x)
{
    switch(type)
    {
        case ADD : return ceil(b*MOD + x, MOD);

        case MULTIPLY : return ceil(b*x, MOD);
    }
}

int main()
{
    int no_of_timesteps, target_bananas;
    cin >> no_of_timesteps >> target_bananas;

    vector <int> can_get(target_bananas + 1, -1), previous_get(target_bananas + 1, false);
    can_get[0] = 0;

    for(int i = 1; i <= no_of_timesteps; i++)
    {
        int type;
        long long x, time;
        cin >> type >> x >> time;
        previous_get = can_get;

        for(int b = 0; b <= target_bananas; b++)
        {   //cout << "From " << b << "\n";
            if(previous_get[b] != -1)
            {
                for(long long t = 1, next = b; t <= time; t++)
                {
                    next = operate(type, next, x); //cout << "Getting " << next << "\n";

                    if(next > target_bananas || previous_get[next] != -1)
                    {
                        break;
                    }

                    can_get[next] = i; //cout << "Can get " << next << " = " << can_get[next] << "\n";
                }
            }
        }
    }

    for(int i = 1; i <= target_bananas; i++)
    {
        cout << can_get[i] << " ";
    }

    return 0;
}
