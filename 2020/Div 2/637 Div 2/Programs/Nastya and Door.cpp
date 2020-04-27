#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int no_of_elements, k;
    cin >> no_of_elements >> k;
    
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    vector <int> is_peak(no_of_elements + 1, false);
    for(int i = 2; i < no_of_elements; i++)
    {
        if(A[i - 1] < A[i] && A[i] > A[i + 1])
        {
            is_peak[i] = true;
        }
    }
    
    vector <int> peak_sum(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        peak_sum[i] = peak_sum[i - 1] + is_peak[i];
    }
    
    int max_peaks = 0, left_border = 1;
    for(int i = k; i <= no_of_elements; i++)
    {
        int right = i - 1, left = i - k + 1;
        int peaks_here = peak_sum[right] - peak_sum[left];
        
        if(peaks_here > max_peaks)
        {
            max_peaks = peaks_here;
            left_border = left;
        }
    }
    
    int max_parts = max_peaks + 1;
    cout << max_parts << " " << left_border << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
