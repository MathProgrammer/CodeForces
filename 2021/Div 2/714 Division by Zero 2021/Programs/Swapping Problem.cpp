#include <iostream>
#include <vector>
#include <map>

using namespace std;

void update_prefix_max(map <int, int> &M)
{
    int prefix_max = 0;
    for(auto it = M.begin(); it != M.end(); it++)
    {
        prefix_max = max(prefix_max, it->second);

        it->second = prefix_max;
    }
}

int main()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector <int> A(no_of_elements + 1), B(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }

    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> B[i];
    }

    map <int, int> X, Y;
    for(int i = 1; i <= no_of_elements; i++)
    {
        if(A[i] <= B[i])
        {
            X[A[i]] = max(X[A[i]], B[i]);
        }
        else
        {
            Y[B[i]] = max(Y[B[i]], A[i]);
        }
    }

    update_prefix_max(X);
    update_prefix_max(Y);

    long long overlap = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        long long overlap_here = 0;

        if(A[i] <= B[i])
        {
            auto it = Y.upper_bound(A[i]);

            if(it != Y.begin())
            {
                it--;
                int left = A[i], right = min(it->second, B[i]);

                overlap_here = right - left;
            }
        }
        else
        {
            auto it = X.upper_bound(B[i]);

            if(it != X.begin())
            {
                it--;

                int left = B[i], right = min(it->second, A[i]);
                overlap_here = right - left;
            }
        }

        overlap = max(overlap, overlap_here);
    }

    long long answer = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        answer += abs(A[i] - B[i]);
    }

    answer -= 2*overlap;

    cout << answer << "\n";
    return 0;
}
