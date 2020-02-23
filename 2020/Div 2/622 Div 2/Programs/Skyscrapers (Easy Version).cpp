#include <iostream>
#include <vector>

using namespace std;

long long count(int P, vector <int> &limit, vector <int> &A)
{
    A[P] = limit[P];
    
    for(int i = P - 1; i >= 1; i--)
    {
        A[i] = min(limit[i], A[i + 1]);
    }
    
    for(int i = P + 1; i < limit.size(); i++)
    {
        A[i] = min(limit[i], A[i - 1]);
    }
    
    long long total = 0;
    for(int i = 1; i < limit.size(); i++)
    {
        total += A[i];
    }
    
    return total;
}

int main()
{
    int no_of_plots;
    cin >> no_of_plots;
    
    vector <int> max_height(no_of_plots + 1);
    for(int i = 1; i <= no_of_plots; i++)
    {
        cin >> max_height[i];
    }
    
    long long max_count = 0;
    vector <int> answer(no_of_plots + 1);
    vector <int> this_answer(no_of_plots + 1);
    
    for(int peak = 1; peak <= no_of_plots; peak++)
    {
        if(count(peak, max_height, this_answer) > max_count)
        {
            max_count = count(peak, max_height, this_answer);
            
            answer = this_answer;
        }
    }
    
    for(int i = 1; i <= no_of_plots; i++)
    {
        cout << answer[i] << " ";
    }
    
    cout << "\n";
    
    return 0;
}
