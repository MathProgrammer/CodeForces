#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_elements, no_of_subarrays;
    cin >> no_of_elements >> no_of_subarrays;

    vector <long long> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
        cin >> A[i];

    vector <long long> costs;
    for(int i = 1; i < no_of_elements; i++)
        costs.push_back(A[i] - A[i + 1]);

    sort(all(costs));

    long long total_cost = A[no_of_elements] - A[1];

    for(int i = 0; i < no_of_subarrays - 1; i++)
        total_cost += costs[i];

    cout << total_cost;
    return 0;
}
