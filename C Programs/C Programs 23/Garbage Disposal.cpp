#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int no_of_days, k;
    cin >> no_of_days >> k;

    vector <long long> A(no_of_days + 1);
    for(int i = 1; i <= no_of_days; i++)
        cin >> A[i];

    long long minimum_bags = 0;

    for(int i = 1; i <= no_of_days; i++)
    {
        minimum_bags += A[i]/k;
        A[i] %= k;

        if(A[i] > 0)
        {
            minimum_bags++;

            if(i + 1 <= no_of_days)
                A[i + 1] = max(0LL, A[i + 1] - (k - A[i]));
        }
    }

    cout << minimum_bags;
    return 0;
}
