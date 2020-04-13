#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int no_of_plots;
    cin >> no_of_plots;
    
    vector <long long> max_height(no_of_plots + 5);
    for(int i = 1; i <= no_of_plots; i++)
    {
        cin >> max_height[i];
    }
    
    stack <long long> greater_than;
    greater_than.push(0);
    
    vector <long long> left_contribution(no_of_plots + 1);
    for(int i = 1; i <= no_of_plots; i++)
    {
        while(max_height[greater_than.top()] > max_height[i])
        {
            greater_than.pop();
        }
        
        left_contribution[i] = max_height[i]*(i - greater_than.top()) + left_contribution[greater_than.top()];
        
        //cout << "Left " << i << " = " << left_contribution[i] << "\n";
        
        greater_than.push(i);
    }
    
    greater_than.pop();
    
    greater_than.push(no_of_plots + 1);
    vector <long long> right_contribution(no_of_plots + 5);
    for(int i = no_of_plots; i >= 1; i--)
    {
        while(max_height[greater_than.top()] > max_height[i])
        {
            greater_than.pop();
        }
        
        right_contribution[i] = max_height[i]*(greater_than.top() - i) + right_contribution[greater_than.top()];
        
        greater_than.push(i);
        
        //cout << "Right " << i << " = " << right_contribution[i] << "\n";
    }
    
    long long answer = 0;
    for(int i = 1; i <= no_of_plots; i++)
    {
        answer = max(answer, left_contribution[i] + right_contribution[i] - max_height[i]);
    }
    
    //cout << answer << "\n";
    int peak = 0;
    for(int i = 1; i <= no_of_plots; i++)
    {
        if(answer == left_contribution[i] + right_contribution[i] - max_height[i])
        {
            peak = i;
            break;
        }
    }
    
    vector <long long> height(no_of_plots + 1);
    
    height[peak] = max_height[peak];
    
    for(int i = peak - 1; i >= 1; i--)
    {
        height[i] = min(max_height[i], height[i + 1]);
    }
    
    for(int i = peak + 1;i <= no_of_plots; i++)
    {
        height[i] = min(max_height[i], height[i - 1]);
    }
    
    for(int i = 1; i <= no_of_plots; i++)
    {
        cout << height[i] << " ";
    }
    
    cout <<"\n";
    
    return 0;
}
