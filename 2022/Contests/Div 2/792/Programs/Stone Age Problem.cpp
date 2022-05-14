#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int no_of_elements, no_of_queries;
    cin >> no_of_elements >> no_of_queries;

    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }

    long long sum = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        sum += A[i];
    }

    int last_replace_all_time = -1, last_replace_all_value = 0;
    vector <int> last_touched(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_queries; i++)
    {
        const int REPLACE_ONE = 1, REPLACE_ALL = 2;
        int query, index, value;
        cin >> query;

        switch(query)
        {
            case REPLACE_ONE: cin >> index >> value;
                              if(last_touched[index] > last_replace_all_time)
                              {
                                  sum += (value - A[index]);
                              }
                              else
                              {
                                  sum += (value - last_replace_all_value);
                              }

                              A[index] = value;
                              last_touched[index] = i;
                              break;

            case REPLACE_ALL: cin >> value;

                              sum = no_of_elements*1LL*value;

                              last_replace_all_value = value;
                              last_replace_all_time = i;
        }

        cout << sum << "\n";
    }

    return 0;
}
