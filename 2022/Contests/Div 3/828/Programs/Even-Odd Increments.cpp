#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void solve()
{
    int no_of_elements, no_of_queries;
    cin >> no_of_elements >> no_of_queries;

    long long even_sum = 0, odd_sum = 0;
    long long even_count = 0, odd_count = 0;
    vector <int> A(no_of_elements + 1);
    for(int i = 0; i < no_of_elements; i++)
    {
        cin >> A[i];

        if(A[i]%2 == 0)
        {
            even_sum += A[i];
            even_count++;
        }
        else if(A[i]%2 == 1)
        {
            odd_sum += A[i];
            odd_count++;
        }
    }

    for(int i = 1; i <= no_of_queries; i++)
    {
        const int ADD_EVEN = 0, ADD_ODD = 1;
        long long query, value;
        cin >> query >> value;

        switch(query)
        {
            case ADD_EVEN : {
                                if(value%2 == 0)
                                {
                                    even_sum += even_count*value;
                                }
                                else
                                {
                                    even_sum += even_count*value;
                                    odd_sum += even_sum;
                                    even_sum = 0;

                                    odd_count += even_count;
                                    even_count = 0;
                                }

                                break;
                            }

            case ADD_ODD : {
                                if(value%2 == 0)
                                {
                                    odd_sum += odd_count*value;
                                }
                                else
                                {
                                    odd_sum += odd_count*value;
                                    even_sum += odd_sum;
                                    odd_sum = 0;

                                    even_count += odd_count;
                                    odd_count = 0;
                                }

                                break;

                            }
        }

        cout << even_sum + odd_sum << "\n";
    }
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}

