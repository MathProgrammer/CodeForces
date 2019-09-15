#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector <int> A(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
        cin >> A[i];

    sort(all(A));

    const int MAX = 101;
    int last_colour = 0;
    vector <int> colour(MAX, 0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        if(colour[A[i]] == 0)
        {
            last_colour++;

            for(int j = A[i]; j < MAX; j += A[i])
            {
                colour[j] = last_colour;
            }
        }
    }

    cout << last_colour;
    return 0;
}
