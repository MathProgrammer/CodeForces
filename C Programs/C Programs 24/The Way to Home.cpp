#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int length, max_jump;
    cin >> length >> max_jump;

    string path;
    cin >> path;

    const int oo = 1e9;
    vector <int> minimum_jumps_to_reach(length, 0);
    minimum_jumps_to_reach[0] = 0;

    for(int i = 1; i < length; i++)
    {
        minimum_jumps_to_reach[i] = oo;

        if(path[i] == '0') continue;

        for(int j = 1; j <= max_jump && i - j >= 0; j++)
        {
            minimum_jumps_to_reach[i] = min(minimum_jumps_to_reach[i], 1 + minimum_jumps_to_reach[i - j]);
        }
    }

    cout << (minimum_jumps_to_reach[length - 1] == oo ? -1 : minimum_jumps_to_reach[length - 1]);
    return 0;
}
