#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

char other(char ch)
{
    return (ch == '1' ? '0' : '1');
}

void solve()
{
    int length;
    cin >> length;

    string A, B;
    cin >> A >> B;

    vector <int> ones(A.size(), 0);
    for(int i = 0; i < A.size(); i++)
    {
        if(i == 0)
        {
            ones[i] = (A[i] == '1');
        }
        else
        {
            ones[i] = ( (A[i] == '1') + ones[i - 1]);
        }

    }

    int flip = false;
    for(int i = A.size() - 1; i >= 0; i--)
    {   //cout << "At " << i << "\n";
        if(2*ones[i] == i + 1)
        {   //cout << "Equal ";
            if(flip)
            {
                if(A[i] == B[i])
                {
                    flip = false;
                }
                else
                {
                    A[i] = other(A[i]);
                    flip = true;
                }
            }
            else
            {
                if(A[i] != B[i])
                {
                    A[i] = other(A[i]);
                    flip = true;
                }
            }
        }
        else
        {
            if(flip)
            {
                A[i] = other(A[i]);
            }
        }

       // cout << "Flip = " << flip << " A = " << A[i] << "\n";
    }

    int same = true;
    for(int i = 0; i < A.size(); i++)
    {
        if(A[i] != B[i])
        {
            same = false;
            break;
        }
    }

    cout << (same ? "YES" : "NO") << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}



