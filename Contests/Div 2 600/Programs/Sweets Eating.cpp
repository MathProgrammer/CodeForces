#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_elements, max_per_day;
    cin >> no_of_elements >> max_per_day;

    vector <int> A(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }

    sort(all(A));

    vector <long long> sum_till(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        sum_till[i] = sum_till[i - 1] + A[i];
    }

    vector <long long> penalty(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        long long day_1 = 0, remaining_days = 0;
        
        if(i <= max_per_day)
        {
            day_1 = sum_till[i];
        }
        else
        {
            day_1 = sum_till[i] - sum_till[i - max_per_day];
            
            remaining_days = penalty[i - max_per_day] + sum_till[i - max_per_day];
        }
        
        penalty[i] = day_1 + remaining_days;
    }

    for(int i = 1; i <= no_of_elements; i++)
    {
        cout << penalty[i] << " ";
    }

    return 0;
}
 
