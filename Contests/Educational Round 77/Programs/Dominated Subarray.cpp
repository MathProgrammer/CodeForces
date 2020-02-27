#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
        cin >> A[i];

    const int MAX = 2e5 + 5;
    vector <int> frequency(MAX, 0);

    int is_dominated = false;
    int smallest_array = MAX;
    int left = 1, right = 0;
    while(right + 1 <= no_of_elements)
    {
        while(right + 1 <= no_of_elements)
        {
            right++;

            frequency[A[right]]++;

            if(frequency[A[right]] >= 2)
            {
                break;
            }
        }

        while(left <= right)
        {
            if(left > no_of_elements)
            {
                break;
            }

            if(A[left] == A[right] && frequency[A[right]] == 2)
            {
                break;
            }

            frequency[A[left]]--;

            left++;
        }

        if(frequency[A[right]] == 2)
        {
            smallest_array = min(smallest_array, right - left + 1);
        }
    }

    cout << (smallest_array == MAX ? -1 : smallest_array) << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}


