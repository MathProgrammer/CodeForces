#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector <long long> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
        cin >> A[i];

    vector <long long> max_till(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
        max_till[i] = max(max_till[i - 1], A[i]);

    vector <long long> max_from(no_of_elements + 2, 0);
    for(int i = no_of_elements; i >= 1; i--)
        max_from[i] = max(max_from[i + 1], A[i]);

    int possible = true;
    for(int i = 2; i < no_of_elements; i++)
        if(max_till[i] > A[i] && max_from[i] > A[i])
            possible = false;

    cout << (possible ? "YES\n" : "NO\n");
    return 0;
}

