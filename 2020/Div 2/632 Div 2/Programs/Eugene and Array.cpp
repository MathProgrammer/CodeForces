#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define all(v) (v).begin(), (v).end()

using namespace std;

int main()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    vector <long long> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    vector <long long> prefix_sum(no_of_elements + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        prefix_sum[i] = prefix_sum[i - 1] + A[i];
    }
    
    int end_point = 0;
    
    map <long long, int> frequency;
    map <long long, int> last_occurence;
    frequency[0] = 1;
    long long answer = 0;
    
    for(int i = 1; i <= no_of_elements; i++)
    {
        if(frequency[prefix_sum[i]] != 0)
        {
            end_point = max(end_point, last_occurence[prefix_sum[i]] + 2);
        }
        
        last_occurence[prefix_sum[i]] = i;
        
        frequency[prefix_sum[i]] = i;
        
        int distance = (end_point == 0 ? i : i - end_point + 1);
    
        answer += (distance > 0 ? distance : 0);
    }
    
    cout << answer << "\n";
    
    return 0;
}
