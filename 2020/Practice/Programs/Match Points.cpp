#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int no_of_elements, distance;
    cin >> no_of_elements >> distance;
    
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    sort(all(A));
    
    int left_pairs = 0, right_pairs = no_of_elements/2 + 1;
    while(right_pairs - left_pairs > 1)
    {
        int mid = (left_pairs + right_pairs)/2;
        
        int good_pairs = 0;
        
        for(int i = 1; i <= mid; i++)
        {
            if(A[no_of_elements - mid + i] - A[i] >= distance)
            {
                good_pairs++;
            }
        }
        
        if(good_pairs == mid)
        {
            left_pairs = mid;
        }
        else
        {
            right_pairs = mid;
        }
    }
    
    int answer = left_pairs;
    
    cout << answer << "\n";
    return 0;
}
