#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_elements, total_chosen, maximum_consecutive;
    cin >> no_of_elements >> total_chosen >> maximum_consecutive;

    vector <long long> A(no_of_elements);
    for(int i = 0; i < no_of_elements; i++)
        cin >> A[i];

    sort(all(A));
    reverse(all(A));

    long long no_of_cycles = total_chosen/(maximum_consecutive + 1);
    long long cycle_total = A[0]*maximum_consecutive + A[1];

    long long remaining = total_chosen%(maximum_consecutive + 1);

    long long total = cycle_total*no_of_cycles + A[0]*remaining;

    cout << total;
    return 0;
}
