#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int no_of_elements, segment_length;
    cin >> no_of_elements >> segment_length;

    vector <long long> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }

    vector <long long> sum_till(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        sum_till[i] = A[i] + sum_till[i - 1];
    }

    vector <long long> best_segment_1_till(no_of_elements + 1);
    vector <int> best_a(no_of_elements + 1);
    for(int i = segment_length; i <= no_of_elements; i++)
    {
        long long this_segment = sum_till[i] - sum_till[i - segment_length];
        best_segment_1_till[i] = best_segment_1_till[i - 1];
        best_a[i] = best_a[i - 1];

        if(this_segment > best_segment_1_till[i - 1])
        {
            best_a[i] = i - segment_length + 1;

            best_segment_1_till[i] = this_segment;
        }
    }

    long long answer = 0, a, b;
    for(int i = segment_length + 1; i + segment_length - 1 <= no_of_elements; i++)
    {
        long long segment_2 = sum_till[i + segment_length - 1] - sum_till[i - 1];
        //cout << "i = " << i << " 1 = " << best_segment_1_till[i - 1] << " 2 = " << segment_2 << "\n";

        if(best_segment_1_till[i - 1] + segment_2 > answer)
        {
            answer = best_segment_1_till[i - 1] + segment_2;

            a = best_a[i - 1];
            b = i;
        }
    }

    cout << a << " " << b << "\n";
    return 0;
}
