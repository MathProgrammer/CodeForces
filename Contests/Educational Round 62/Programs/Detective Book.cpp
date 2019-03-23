#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int no_of_pages;
    cin >> no_of_pages;

    vector <int> page(no_of_pages + 1, 0);
    for(int i = 1; i <= no_of_pages; i++)
        cin >> page[i];

    int no_of_days = 0, day_target = 0;
    for(int i = 1; i <= no_of_pages; i++)
    {
        day_target = max(day_target, page[i]);

        if(day_target == i)
        {
            day_target = 0;

            no_of_days++;
        }
    }

    cout << no_of_days;
    return 0;
}
