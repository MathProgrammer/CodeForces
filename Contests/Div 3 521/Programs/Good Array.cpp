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

    const int MAX = 1e6 + 5;
    vector <int> frequency(MAX, 0);
    for(int i = 1; i <= no_of_elements; i++)
        frequency[A[i]]++;

    long long sum = 0;
    for(int i = 1; i <= no_of_elements; i++)
        sum += A[i];

    vector <int> nice_indices;
    for(int i = 1; i <= no_of_elements; i++)
    {
        long long remaining_sum = sum - A[i];
        long long target = remaining_sum/2;

        if(target < MAX && remaining_sum%2 == 0 && frequency[target] > 0 &&
           !(frequency[target] == 1 and A[i] == target))
        {
            nice_indices.push_back(i);
        }
    }

    cout << nice_indices.size() << "\n";
    for(int i = 0; i < nice_indices.size(); i++)
        cout << nice_indices[i] << " ";

    return 0;
}

