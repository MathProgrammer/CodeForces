#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve()
{
    int no_of_elements, no_of_distinct_elements, segment_length;
    cin >> no_of_elements >> no_of_distinct_elements >> segment_length;

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }

    int distinct_elements = 0;
    map <int, int> last_occurence;
    for(int i = 1; i <= segment_length; i++)
    {
        if(last_occurence[A[i]] == 0)
        {
            distinct_elements++;
        }

        last_occurence[A[i]] = i;
    }

    int minimum_distinct_elements = distinct_elements;
    for(int i = segment_length + 1; i <= no_of_elements; i++)
    {
        int left = i - segment_length, right = i;
        int left_element = A[left], right_element = A[right];

        if(last_occurence[left_element] == left)
        {
            distinct_elements--;
        }

        if(last_occurence[right_element] <= left)
        {
            distinct_elements++;
        }

        last_occurence[right_element] = i;

        minimum_distinct_elements = min(minimum_distinct_elements, distinct_elements);
    }

    cout << minimum_distinct_elements << "\n";
}

int main()
{
    int no_of_tests;
    cin >> no_of_tests;

    while(no_of_tests--)
    {
        solve();
    }

    return 0;
}
