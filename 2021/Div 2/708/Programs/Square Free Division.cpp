#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int MAX_N = 1e7 + 5, oo = 1e9;
vector  <int> primes;
vector <int> value(MAX_N, 1);
vector <int> frequency(MAX_N, 0);

void sieve(int n)
{
    vector <int> largest_prime_factor(MAX_N, 0);

    for(long long i = 2; i < MAX_N; i++)
    {
        if(largest_prime_factor[i] == 0)
        {
            for(long long multiple = i; multiple < MAX_N; multiple += i)
            {
                largest_prime_factor[multiple] = i;
            }
        }
    }

    for(int i = 2; i < MAX_N; i++)
    {
        int current = i, exponent = 0;

        while(current%largest_prime_factor[i] == 0)
        {
            current /= largest_prime_factor[i];

            exponent++;
        }

        value[i] = value[current];

        if(exponent%2 == 1)
        {
            value[i] *= largest_prime_factor[i];
        }
    }
}

void solve()
{
    int no_of_elements, no_of_changes;
    cin >> no_of_elements >> no_of_changes;

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];

        A[i] = value[A[i]]; //cout << A[i] << " ";

        frequency[A[i]] = 0;
    }
    //cout << "\n";

    vector <vector <int> > best_left(no_of_elements + 1, vector <int> (no_of_changes + 1));
    for(int change = 0; change <= no_of_changes; change++)
    {   //cout << "Change = " << change << "\n";
        int left = no_of_elements + 1, right = no_of_elements, duplicates = 0;

        while(right >= 1)
        {
            while(left >= 1)
            {
                if(duplicates == change && frequency[A[left - 1]] > 0)
                {
                    break;
                }

                if(frequency[A[left - 1]] > 0)
                {
                    duplicates++;
                }

                frequency[A[left - 1]]++;
                left--;
            }

            best_left[right][change] = max(left, 1); //cout << "For " << right << " best " << left << "\n";

            if(frequency[A[right]] > 1)
            {
                duplicates--;
            }

            frequency[A[right]]--;
            right--;
        }
    }

    int answer = oo;
    vector <vector <int> > minimum_segments(no_of_elements + 1, vector <int> (no_of_changes + 1, oo));
    for(int i = 1; i <= no_of_elements; i++)
    {
        for(int changes = 0; changes <= no_of_changes; changes++)
        {
            if(changes > 0)
            {
                minimum_segments[i][changes] = minimum_segments[i][changes - 1];
            }

            for(int last_changes = 0; last_changes <= changes; last_changes++)
            {
                int left = best_left[i][last_changes];

                if(left == 1)
                {
                    minimum_segments[i][changes] = 1;
                    continue;
                }

                minimum_segments[i][changes] = min(minimum_segments[i][changes],
                                                    minimum_segments[left - 1][changes - last_changes] + 1);

            }
        }
    }

    for(int i = 0; i <= no_of_changes; i++)
    {
        answer = min(answer, minimum_segments[no_of_elements][i]);
    }

    cout << answer << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve(MAX_N);

    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
    {
        solve();
    }

    return 0;
}
