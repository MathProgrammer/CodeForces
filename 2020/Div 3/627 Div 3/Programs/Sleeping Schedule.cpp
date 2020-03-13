#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2005;
int max_ways[MAX_N][MAX_N];

int main()
{
    int no_of_times, no_of_hours, left, right;
    cin >> no_of_times >> no_of_hours >> left >> right;
    
    vector <int> A(no_of_times + 1, 0);
    for(int i = 1; i <= no_of_times; i++)
    {
        cin >> A[i];
    }
    
    for(int i = no_of_times; i >= 1; i--)
    {
        if(i == no_of_times)
        {
            for(int start = 0; start < no_of_hours; start++)
            {
                max_ways[i][start] = (left <= start && start <= right);
            }
            
            continue;
        }
        
        for(int start = 0; start < no_of_hours; start++)
        {
            int next_start_1 = (start + A[i + 1])%no_of_hours;
            int next_start_2 = (start + A[i + 1] - 1 + no_of_hours)%no_of_hours;
            
            int best_next_start;
            
            if(max_ways[i + 1][next_start_1] < max_ways[i + 1][next_start_2])
            {
                best_next_start = next_start_2;
            }
            else
            {
                best_next_start = next_start_1;
            }
            
            max_ways[i][start] = (left <= start && start <= right) + max_ways[i + 1][best_next_start];
        }
    }
    
    int answer = max(max_ways[1][A[1]], max_ways[1][A[1] - 1]);
    
    cout << answer << "\n";
    return 0;
}
