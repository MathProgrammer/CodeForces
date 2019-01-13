#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cstring>

using namespace std;

const int MAX_N = 2005;
double probability[MAX_N][MAX_N];

int main()
{
    int no_of_people, total_time;
    double new_person_probability;
    cin >> no_of_people >> new_person_probability >> total_time;

    double no_new_person_probability = 1 - new_person_probability;

    memset(probability, 0, sizeof(probability));
    probability[0][0] = 1;

    for(int t = 1; t <= total_time; t++)
    {
        probability[0][t] = no_new_person_probability*probability[0][t - 1];

        for(int i = 1; i < no_of_people; i++)
        {
            probability[i][t] = new_person_probability*probability[i - 1][t - 1] +
                                no_new_person_probability*probability[i][t - 1];

        }

        probability[no_of_people][t] = probability[no_of_people][t - 1] +
                        new_person_probability*probability[no_of_people - 1][t - 1];
    }

    double expectation = 0;
    for(int i = 1; i <= no_of_people; i++)
        expectation += i*probability[i][total_time];

    cout << setprecision(7) << expectation;

    return 0;
}
