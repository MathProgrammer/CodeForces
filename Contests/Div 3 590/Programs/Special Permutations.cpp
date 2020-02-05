#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, no_of_elements;
    cin >> n >> no_of_elements;
    
    vector <int> X(no_of_elements + 1);
    vector <int> position(n + 1, 0);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> X[i];
        
        position[X[i]] = X[i];
    }
    
    vector <vector <int> > pairs(n + 1);
    vector <int> segments_starting_at(n + 1, 0);
    vector <int> segments_ending_at(n + 1, 0);
    for(int i = 1; i < no_of_elements; i++)
    {
        if(abs(X[i] - X[i + 1]) >= 2)
        {
            segments_starting_at[min(X[i], X[i + 1]) + 1]++;
            segments_ending_at[max(X[i], X[i + 1]) - 1]++;
        }
        
        pairs[X[i]].push_back(X[i + 1]);
        pairs[X[i + 1]].push_back(X[i]);
    }
    
    vector <long long> segments_covering(n + 1, 0);
    for(int i = 1; i <= n; i++)
    {
        segments_covering[i] = segments_covering[i - 1] + segments_starting_at[i] - segments_ending_at[i - 1];
    }
    
    vector <long long> answer(n + 1, 0);
    for(int i = 1; i < no_of_elements; i++)
    {
        answer[1] += abs(X[i] - X[i + 1]);
    }
    
    for(int i = 2; i <= n; i++)
    {
        answer[i] = answer[1] - segments_covering[i];
        
        for(int j = 0; j < pairs[i].size(); j++)
        {
            int d = pairs[i][j];
            
            if(d == i)
            {
                continue;
            }
            
            if(d < i)
            {
                answer[i] += abs(d + 1 - 1) - abs(d - i);
            }
            
            if(d > i)
            {
                answer[i] += abs(d - 1) - abs(d - i);
            }
        }
    }
    
    for(int i = 1; i <= n; i++)
    {
        cout << answer[i] << " ";
    }
    
    cout << "\n";
    return 0;
}
