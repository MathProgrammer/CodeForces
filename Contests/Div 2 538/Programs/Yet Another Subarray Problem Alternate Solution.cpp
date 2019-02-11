#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

struct info
{
    int index, value;

    info(int i, int v)
    {
        index = i; value = v;
    }

    const int operator<(const info &X)
    {
        return (value < X.value);
    }
};

int main()
{
    int no_of_elements, min_size, no_of_subarrays;
    cin >> no_of_elements >> min_size >> no_of_subarrays;

    vector <info> A;
    for(int i = 0; i < no_of_elements; i++)
    {
        int element;

        cin >> element;

        A.push_back(info(i, element));
    }

    sort(all(A));
    reverse(all(A));

    int greatest_elements = min_size*no_of_subarrays;
    long long total_sum = 0;
    vector <int> special_index(greatest_elements);
    for(int i = 0; i < greatest_elements; i++)
    {
        total_sum += A[i].value;

        special_index[i] = A[i].index + 1;
    }

    sort(all(special_index));

    vector <int> partition_points(no_of_subarrays);
    for(int i = 0; i < no_of_subarrays; i++)
    {
        partition_points[i] = special_index[(i + 1)*min_size - 1];
    }

    cout << total_sum << "\n";
    for(int i = 0; i < no_of_subarrays - 1; i++)
        cout << partition_points[i] << " ";

    return 0;
}
