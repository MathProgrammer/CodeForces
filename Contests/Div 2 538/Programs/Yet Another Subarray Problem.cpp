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
    vector <int> is_special(no_of_elements, false);
    for(int i = 0; i < greatest_elements; i++)
    {
        is_special[A[i].index] = true;

        total_sum += A[i].value;
    }

    int no_of_subarrays_made = 0, current_subarray_special_elements = 0;
    vector <int> partition_points;
    for(int i = 0; i < no_of_elements; i++)
    {
        current_subarray_special_elements += (is_special[i]);

        if(current_subarray_special_elements == min_size)
        {
            partition_points.push_back(i + 1);

            no_of_subarrays_made++;

            current_subarray_special_elements = 0;
        }
    }

    cout << total_sum << "\n";
    for(int i = 0; i < no_of_subarrays_made - 1; i++)
        cout << partition_points[i] << " ";

    return 0;
}

