#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int no_of_elements, range;
    cin >> no_of_elements >> range;
    
    vector <pair <int, int> > A(no_of_elements);
    for(int i = 0; i < no_of_elements; i++)
    {
        cin >> A[i].first >> A[i].second;
    }
    
    vector <int> minimum_cost(range + 1);
    for(int i = 0; i <= range; i++)
    {
        minimum_cost[i] = (i);
        
        for(int j = 0; j < no_of_elements; j++)
        {
            int left = max(0, A[j].first - A[j].second), right = min(range, A[j].first + A[j].second);
            
            if(left <= i && i <= right)
            {
                minimum_cost[i] = (i == 0 ? 0 : minimum_cost[i - 1]);
                break;
            }
            
            if(right < i)
            {
                int additional_cost = i - right;
                int previous_antenna = max(0, left - additional_cost - 1);
                
                minimum_cost[i] = min(minimum_cost[i], additional_cost + minimum_cost[previous_antenna]);
            }
        }
        
    }
    
    cout << minimum_cost[range] << "\n";
    return 0;
}
