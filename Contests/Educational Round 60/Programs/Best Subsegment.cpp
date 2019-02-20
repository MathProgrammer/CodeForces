#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
        cin >> A[i];

    int maximum = 0;
    for(int i = 1; i <= no_of_elements; i++)
        maximum = max(maximum, A[i]);

    int max_longest_segment = 0, longest_segment_here = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        if(A[i] != maximum)
        {
            longest_segment_here = 0;
        }
        else
        {
            longest_segment_here++;

            max_longest_segment = max(max_longest_segment, longest_segment_here);
        }
    }

    cout << max_longest_segment;
    return 0;
}
