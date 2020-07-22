#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    
    vector <int> P(2*n + 5);
    for(int i = 1; i <= 2*n; i++)
    {
        cin >> P[i];
    }
    
    vector <int> sequences;
    int length = 1, beginning = P[1];
    for(int i = 2; i <= 2*n; i++)
    {
        if(P[i] > beginning)
        {
            sequences.push_back(length);
            
            beginning = P[i];
            length = 1;
        }
        else
        {
            length++;
        }
    }
    sequences.push_back(length);
    
    vector <vector <int> > possible_sums(n + 1, vector <int> (sequences.size() + 1, false));
    for(int s = 0; s <= n; s++)
    {
        for(int i = 0; i < sequences.size(); i++)
        {
            if(s == 0)
            {
                possible_sums[s][i] = true;
                continue;
            }
            
            if(i == 0)
            {
                possible_sums[s][i] = (s == sequences[i] ? true : false);
                
                continue;
            }
            
            possible_sums[s][i] = possible_sums[s][i - 1];
            
            if(s >= sequences[i])
            {
                possible_sums[s][i] = (possible_sums[s][i - 1] ||
                                       possible_sums[s - sequences[i]][i - 1]);
            }
        }
    }
    
    cout << (possible_sums[n][sequences.size() - 1] ? "YES\n" : "NO\n");
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}


