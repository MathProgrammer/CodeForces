#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }

    const int MAX_N = 1e6 + 5;
    int possible = true;

    int no_of_people = 0;
    vector <int> no_of_entries_today(MAX_N, 0);
    vector <int> people_today;

    vector <int> has_entered(1e6 + 5, 0);
    vector <int> day_events;
    for(int left = 1, right = 1; right <= no_of_elements; right++)
    {
        if(A[right] > 0)
        {
            has_entered[A[right]] = true;
            no_of_people++;

            people_today.push_back(A[right]);

            no_of_entries_today[A[right]]++;

            if(no_of_entries_today[A[right]] > 1)
            {
                possible = false;

                break;
            }
        }
        else if(A[right] < 0)
        {
            if(!has_entered[-A[right]])
            {
                possible = false;

                break;
            }

            has_entered[-A[right]] = false;

            no_of_people--;
        }

        if(no_of_people == 0)
        {
            day_events.push_back(right - (left - 1));

            left = right + 1;

            for(int p = 0; p < people_today.size(); p++)
            {
                no_of_entries_today[people_today[p]] = 0;
            }

            people_today.clear();
        }
    }

    if(no_of_people > 0)
    {
        possible = false;
    }

    if(!possible)
    {
        cout << "-1\n";

        return 0;
    }

    cout << day_events.size() << "\n";
    for(int i = 0; i < day_events.size(); i++)
    {
        cout << day_events[i] << " ";
    }

    return 0;
}
