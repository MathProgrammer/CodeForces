#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

long long no_of_elements, relocate, destroy, add;
vector <int> height;
vector <long long> sum_till;
const long long oo = 1e18;

long long calculate(long long h)
{
    int l = lower_bound(all(height), h) - height.begin() - 1;
    int r = upper_bound(all(height), h) - height.begin();
    
    long long missing_blocks = l*h - sum_till[l];
    long long extra_blocks = sum_till[no_of_elements] - sum_till[r - 1] - h*(no_of_elements - r + 1);
    
    long long cost = relocate*min(missing_blocks, extra_blocks);
    
    if(missing_blocks > extra_blocks)
    {
        cost += add*(missing_blocks - extra_blocks);
    }
    else if(extra_blocks > missing_blocks)
    {
        cost += destroy*(extra_blocks - missing_blocks);
    }
    
    //Overflow
    if(cost < 0)
    {
        cost = oo;
    }
    
    return cost;
}

int main()
{
    cin >> no_of_elements >> add >> destroy >> relocate;
    relocate = min(relocate, add + destroy);
    
    height.resize(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> height[i];
    }
    
    sort(all(height));
    
    sum_till.resize(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        sum_till[i] = sum_till[i - 1] + height[i];
    }
    
    const long long RANGE = 2;
    long long left = height[1], right = height[no_of_elements];
    while(right - left > RANGE)
    {
        long long mid_1 = left + (right - left)/3, mid_2 = right - (right - left)/3;
        
        if(calculate(mid_1) > calculate(mid_2))
        {
            left = mid_1;
        }
        else
        {
            right = mid_2;
        }
    }
    
    long long answer = min(calculate(left), calculate(right));
    for(long long i = left; i <= right; i++)
    {
        answer = min(answer, calculate(i));
    }
    
    cout << answer << "\n";
    return 0;
}
