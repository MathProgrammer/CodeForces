#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int no_of_students;
    cin >> no_of_students;

    vector <int> rating(no_of_students + 1);
    vector <int> was_odd(no_of_students + 1, false);

    int sum = 0;
    for(int i = 1; i <= no_of_students; i++)
    {
        cin >> rating[i];

        was_odd[i] = (abs(rating[i])%2 == 1);

        rating[i] /= 2;

        sum += rating[i];
    }

    if(sum < 0)
    {
        for(int i = 1; i <= no_of_students && sum != 0; i++)
        {
            if(was_odd[i] && rating[i] > 0)
            {
                rating[i]++;

                sum++;
            }
        }
    }
    else if(sum > 0)
    {
        for(int i = 1; i <= no_of_students && sum != 0; i++)
        {
            if(was_odd[i] && rating[i] < 0)
            {
                rating[i]--;

                sum--;
            }
        }
    }

    for(int i = 1; i <= no_of_students; i++)
    {
        cout << rating[i] << "\n";
    }

    return 0;
}
