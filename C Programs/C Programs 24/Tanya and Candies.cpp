#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 5, EVEN = 0, ODD = 1;
long long sum_till[MAX_N][2], sum_from[MAX_N][2];

int main()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector <int> A(no_of_elements);
    for(int i = 1; i <= no_of_elements; i++)
        cin >> A[i];

    sum_till[0][ODD] = sum_till[0][EVEN] = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        sum_till[i][ODD] = sum_till[i - 1][ODD];
        sum_till[i][EVEN] = sum_till[i - 1][EVEN];

        sum_till[i][i%2] += A[i];
    }

    sum_from[no_of_elements + 1][ODD] = sum_from[no_of_elements + 1][EVEN] = 0;
    for(int i = no_of_elements; i >= 1; i--)
    {
        sum_from[i][ODD] = sum_from[i + 1][ODD];
        sum_from[i][EVEN] = sum_from[i + 1][EVEN];

        sum_from[i][i%2] += A[i];
    }

    int no_of_points = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        no_of_points += (sum_till[i - 1][EVEN] + sum_from[i + 1][ODD] == sum_till[i - 1][ODD] + sum_from[i + 1][EVEN]);
    }

    cout << no_of_points;
    return 0;
}
