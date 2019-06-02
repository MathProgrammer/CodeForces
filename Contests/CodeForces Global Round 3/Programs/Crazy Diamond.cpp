#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1e6 + 5;
vector <int> A(MAX_N);
vector <int> position(MAX_N);
vector <pair <int, int> > swaps;

void arrange_swaps(int start, int destination)
{
    int original_start = A[start], original_destination = A[destination];
    swap(A[start], A[destination]);

    position[original_start] = destination;
    position[original_destination] = start;

    swaps.push_back(make_pair(start, destination));
}

int main()
{
    int no_of_elements;
    cin >> no_of_elements;

    for(int i =1 ; i <= no_of_elements; i++)
        cin >> A[i];

    for(int i = 1; i <= no_of_elements; i++)
        position[A[i]] = i;

    for(int i = 1; i <= no_of_elements; i++)
    {
        if(i == A[i])
            continue;

        int target = i;
        int target_position = position[target];

        int left = min(target_position, i);
        int right = max(target_position, i);

        if(right - left >= no_of_elements/2)
        {
            arrange_swaps(i, target_position);

            continue;
        }

        if(left > no_of_elements/2)
        {
            arrange_swaps(1, left);
            arrange_swaps(1, right);
            arrange_swaps(left, 1);
        }
        else if(right <= no_of_elements/2)
        {
            arrange_swaps(right, no_of_elements);
            arrange_swaps(no_of_elements, left);
        }
        else
        {
            arrange_swaps(left, no_of_elements);
            arrange_swaps(no_of_elements, 1);
            arrange_swaps(1, right);

            arrange_swaps(1, no_of_elements);
            arrange_swaps(no_of_elements, left);
        }
    }

    cout << swaps.size() << "\n";
    for(int i = 0; i < swaps.size(); i++)
        cout << swaps[i].first << " " << swaps[i].second << "\n";

    return 0;
}
