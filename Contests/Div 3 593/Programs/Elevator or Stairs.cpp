#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int no_of_floors, overhead;
    cin >> no_of_floors >> overhead;

    vector <int> stairs(no_of_floors + 1, 0);
    for(int i = 1; i < no_of_floors; i++)
    {
        cin >> stairs[i];
    }

    vector <int> elevator(no_of_floors + 1, 0);
    for(int i = 1; i < no_of_floors; i++)
    {
        cin >> elevator[i];
    }

    const int STAIRS = 0, ELEVATOR = 1;
    vector <vector <int> > minimum_time(no_of_floors + 1, vector <int> (2, 0));
    minimum_time[1][STAIRS] = 0, minimum_time[1][ELEVATOR] = overhead;

    for(int i = 2; i <= no_of_floors; i++)
    {
        minimum_time[i][STAIRS]   = stairs[i - 1] + min(minimum_time[i - 1][STAIRS], minimum_time[i - 1][ELEVATOR]);

        minimum_time[i][ELEVATOR] = elevator[i - 1] + min(minimum_time[i - 1][ELEVATOR], minimum_time[i - 1][STAIRS] + overhead);
    }

    for(int i = 1; i <= no_of_floors; i++)
    {
        cout << min(minimum_time[i][STAIRS], minimum_time[i][ELEVATOR]) << " ";
    }

    cout << "\n";

    return 0;
}
