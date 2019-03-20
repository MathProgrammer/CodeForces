#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int length;
    cin >> length;

    vector <int> difference(length);
    for(int i = 1; i <= length - 1; i++)
        cin >> difference[i];

    vector <int> permutation(length + 1);
    permutation[1] = 1;
    int minimum = 1, maximum = 1;
    for(int i = 2; i <= length; i++)
    {
        permutation[i] = permutation[i - 1] + difference[i - 1];

        minimum = min(minimum, permutation[i]);
        maximum = max(maximum, permutation[i]);
    }

    if(minimum < 1)
    {
        for(int i = 1; i <= length; i++)
            permutation[i] += abs(minimum) + 1;
    }

    if(maximum > length)
    {
        for(int i = 1; i <= length; i++)
            permutation[i] -= (maximum - length);
    }

    int is_permutation = true;
    vector <int> frequency(length + 1, 0);
    for(int i = 1; i <= length; i++)
    {
        if(permutation[i] < 1 || permutation[i] > length)
        {
            is_permutation = false;
            continue;
        }

        frequency[permutation[i]]++;
    }

    for(int i = 1; i <= length; i++)
    {
        if(frequency[i] != 1)
            is_permutation = false;
    }

    if(!is_permutation)
    {
        cout << "-1\n";
        return 0;
    }

    for(int i = 1; i <= length; i++)
        cout << permutation[i] << " ";

    return 0;
}
