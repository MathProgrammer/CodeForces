#include <iostream>
#include <vector>

#define max(a, b) (a > b ? a : b)
using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    int max_n = 0;
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
        
        max_n = max(max_n, A[i]);
    }
    
    vector <vector <int> > position(max_n + 1);
    vector <vector <int> > frequency(max_n + 1, vector <int> (no_of_elements + 1, 0));
    for(int i = 1; i <= no_of_elements; i++)
    {
        position[A[i]].push_back(i);
        
        for(int alpha = 1; alpha <= max_n; alpha++)
        {
            frequency[alpha][i] = frequency[alpha][i - 1];
        }
        
        frequency[A[i]][i]++;
    }
    
    int answer = 0;
    for(int i = 1; i <= max_n; i++)
    {
        answer = max(answer, position[i].size());
        
        for(int p = 0; 2*p < position[i].size(); p++)
        {
            int left = position[i][p] + 1;
            int right = position[i][position[i].size() - p - 1] - 1;
            
            if(left > right)
            {
                break;
            }
            
            int max_middle = 0;
            for(int middle = 1; middle <= max_n; middle++)
            {
                int middle_frequency = frequency[middle][right] - frequency[middle][left - 1];
                
                max_middle = max(max_middle, middle_frequency);
            }
            
    
            answer = max(answer, 2*(p + 1) + max_middle);
        }
    }
        
    cout << answer << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
