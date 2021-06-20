#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define all(v) (v).begin(), (v).end()

using namespace std;

long long ceil(long long numerator, long long denominator)
{
    return (numerator/denominator) + (numerator%denominator != 0);
}

int main()
{
    int no_of_elements;
    long long new_additions, difference;
    cin >> no_of_elements >> new_additions >> difference;

    vector <long long> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }

    sort(all(A));

    priority_queue <long long, vector <long long>, greater <long long> > PQ;
    for(int i = 2; i <= no_of_elements; i++)
    {
        if(A[i] - A[i - 1] > difference)
        {
            PQ.push(A[i] - A[i - 1]);
        }
    }

    while(new_additions > 0 && PQ.size() > 0)
    {
        long long current = PQ.top(); //cout << "Current = " << current << "\n";

        long long required_new_additions = ceil(current,difference) - 1;

        long long possible_additions = min(required_new_additions, new_additions);

        if(possible_additions >= required_new_additions)
        {
            PQ.pop();
        }

        new_additions -= possible_additions; //cout << "Operations = " << new_additions << "\n";
    }

    int groups = PQ.size() + 1;
    cout << groups << "\n";

    return 0;
}
