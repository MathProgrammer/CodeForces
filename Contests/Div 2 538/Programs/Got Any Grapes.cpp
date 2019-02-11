#include <iostream>

using namespace std;

int main()
{
    int green_want, black_want, purple_want;
    cin >> green_want >> black_want >> purple_want;

    int green_have, black_have, purple_have;
    cin >> green_have >> black_have >> purple_have;

    if(green_have > green_want)
    {
        int excess = green_have - green_want;

        green_have -= excess;
        black_have += excess;
    }

    if(black_have > black_want)
    {
        int excess = black_have - black_want;

        black_have -= excess;
        purple_have += excess;
    }

    cout << (green_want <= green_have && black_want <= black_have && purple_want <= purple_have ? "YES\n" : "NO\n");
    return 0;
}
