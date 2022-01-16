#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }

    const int MAX_N = 1e6 + 5;
    vector <int> is_present(MAX_N, false);
    for(int i = 1; i <= no_of_elements; i++)
    {
        is_present[A[i]] = true;
    }

    vector <int> multiple_gcd(MAX_N, 0);
    for(int i = 1; i < MAX_N; i++)
    {
        for(int multiple = i; multiple < MAX_N; multiple += i)
        {
            if(is_present[multiple])
            {
                multiple_gcd[i] = __gcd(multiple_gcd[i], multiple);
            }
        }
    }

    int new_elements = 0;
    for(int i = 1; i < MAX_N; i++)
    {
        if(!is_present[i] && multiple_gcd[i] == i)
        {
            new_elements++;
        }
    }

    cout << new_elements << "\n";
    return 0;
}



