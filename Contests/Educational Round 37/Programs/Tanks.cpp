#include <iostream>
#include <vector>

using namespace std;

long long ceil(long long n, long long r)
{
    return (n/r) + (n%r != 0);
}

int main()
{
    long long no_of_elements, capacity, total_volume;
    cin >> no_of_elements >> capacity >> total_volume;

    vector <long long> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }

    int sum = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        sum += A[i];
    }

    vector < vector <int> > reachable(no_of_elements + 1, vector <int> (capacity + 1, false));
    reachable[0][0] = true;
    for(int i = 1; i <= no_of_elements; i++)
    {
        reachable[i][A[i]%capacity] = true;

        for(int m = 0; m < capacity; m++)
        {
            int new_m = (m + A[i])%capacity;

            if(reachable[i - 1][m])
            {
                reachable[i][new_m] = true;

                reachable[i][m] = true;
            }
        }
    }

    if(sum < total_volume || !reachable[no_of_elements][total_volume%capacity])
    {
        cout << "NO\n";

        return 0;
    }

    cout << "YES\n";
    vector <int> is_good(no_of_elements + 1, false);
    for(int i = no_of_elements, looking_for = total_volume%capacity; i >= 1; i--)
    {
        int remaining = (looking_for - A[i]%capacity + capacity)%capacity;

        if(reachable[i - 1][remaining])
        {
            is_good[i] = true;

            looking_for = remaining;
        }

        if(looking_for == 0)
        {
            break;
        }
    }

    vector <int> good_set, bad_set;
    for(int i = 1; i <= no_of_elements; i++)
    {
        if(is_good[i])
        {
            good_set.push_back(i);
        }
        else
        {
            bad_set.push_back(i);
        }
    }

    for(int i = 1; i < good_set.size(); i++)
    {
        if(A[good_set[i]] == 0)
        {
            continue;
        }

        cout << ceil(A[good_set[i]], capacity) << " " << good_set[i] << " " << good_set[0] << "\n";

        A[good_set[0]] += A[good_set[i]];
        A[good_set[i]] = 0;
    }

    if(good_set.size() > 0 && A[good_set[0]] > total_volume)
    {
        int other;
        if(good_set.size() >= 2)
        {
            other = good_set[1];
        }
        else
        {
            other = bad_set[0];
        }

        cout << (A[good_set[0]] - total_volume)/capacity << " " << good_set[0] << " " << other << "\n";

        A[other] += (A[good_set[0]] - total_volume)/capacity;
        A[good_set[0]] = total_volume;
    }

    for(int i = 1; i < bad_set.size(); i++)
    {
        if(A[bad_set[i]] == 0)
        {
            continue;
        }

        cout << ceil(A[bad_set[i]], capacity) << " " << bad_set[i] << " " << bad_set[0] << "\n";

        A[bad_set[0]] += A[bad_set[i]];
        A[bad_set[i]] = 0;

        if(total_volume%capacity == 0)
        {
            good_set.push_back(bad_set[i]);
        }
    }

    if(A[good_set[0]] < total_volume)
    {
        int extra = total_volume - A[good_set[0]];

        cout << ceil(extra,capacity) << " " << bad_set[0] << " " << good_set[0] << "\n";

        A[good_set[0]] += extra;
        A[bad_set[0]] -= extra;
    }

    return 0;
}
