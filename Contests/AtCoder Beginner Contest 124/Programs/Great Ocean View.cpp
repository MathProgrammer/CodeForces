#include <iostream>

using namespace std;

int main()
{
    int no_of_hills;
    cin >> no_of_hills;

    int max_so_far = 0;
    int no_of_visible_hills = 0;
    for(int i = 1; i <= no_of_hills; i++)
    {
        int height;
        cin >> height;

        no_of_visible_hills += (height >= max_so_far);

        max_so_far = max(max_so_far, height);
    }

    cout << no_of_visible_hills;
    return 0;
}
