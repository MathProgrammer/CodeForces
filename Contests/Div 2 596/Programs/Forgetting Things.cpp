#include <iostream>

using namespace std;

int main()
{
    int old_left, new_left;
    cin >> old_left >> new_left;

    if(old_left == new_left)
    {
        cout << old_left << "1 " << new_left << "2\n";
    }
    else if(old_left + 1 == new_left)
    {
        cout << old_left << "9 " << new_left << "0\n";
    }
    else if(old_left == 9 && new_left == 1)
    {
        cout << old_left << "9 " << new_left << "00\n";
    }
    else
    {
        cout << "-1\n";
    }

    return 0;
}
