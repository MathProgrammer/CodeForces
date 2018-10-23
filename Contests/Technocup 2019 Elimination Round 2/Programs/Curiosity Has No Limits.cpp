#include <iostream>
#include <vector>

using namespace std;

int is_possible(vector <int> &T, vector <int> &A, vector <int> &B, int n)
{
    if(n == 0)
        return true;

    for(int ele = 0; ele <= 3; ele++)
    {
        T[n] = ele;

        if((T[n]|T[n + 1]) == A[n] && (T[n]&T[n + 1]) == B[n])
        {
            if(is_possible(T, A, B, n - 1))
                return true;
        }
    }

    return false;
}

int main()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i < no_of_elements; i++)
        cin >> A[i];

    vector <int> B(no_of_elements + 1);
    for(int i = 1; i < no_of_elements; i++)
        cin >> B[i];

    vector <int> T(no_of_elements + 1);
    for(int i = 0; i <= 3; i++)
    {
        T[no_of_elements] = i;

        if(is_possible(T, A, B, no_of_elements - 1))
        {
            cout << "YES\n";

            for(int i = 1; i <= no_of_elements; i++)
                cout << T[i] << " ";

            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}
