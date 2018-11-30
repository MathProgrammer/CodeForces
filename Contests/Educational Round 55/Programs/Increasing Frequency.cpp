#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int MAX_N = 5e5 + 5, oo = 1e9;
vector <int> position[MAX_N];

int main()
{
    int no_of_elements, target;
    cin >> no_of_elements >> target;


    vector <int> A(no_of_elements + 1);
    vector <int> sum(no_of_elements + 1, 0);

    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];

        position[A[i]].push_back(i);

        sum[i] = sum[i - 1] + (A[i] == target);
    }

    int maximum_changes = 0;

    for(int i = 0; i < MAX_N; i++)
    {
        if(i == target) continue;

        int max_ending_here = 0;

        for(int j = 0; j < position[i].size(); j++)
        {
            int p = position[i][j], q = (j == 0 ? 0 : position[i][j - 1]);

            int no_of_minus_ones = sum[p] - sum[q];

            max_ending_here = max(max_ending_here - no_of_minus_ones + 1, 1);

            maximum_changes = max(maximum_changes, max_ending_here);
        }
    }

    int target_frequency = position[target].size();
    int maximum_occurences = maximum_changes + target_frequency;

    cout << maximum_occurences;

    return 0;
}
