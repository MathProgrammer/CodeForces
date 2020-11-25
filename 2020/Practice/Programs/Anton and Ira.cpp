#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    vector <int> P(no_of_elements + 1), S(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> P[i];
    }
    
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> S[i];
    }
    
    vector <int> label(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        label[S[i]] = i;
    }
    
    for(int i = 1; i <= no_of_elements; i++)
    {
        P[i] = label[P[i]];
    }
    
    long long cost = 0;
    vector <pair <int, int> > swaps;
    
    for(int current = no_of_elements, i; current >= 1; current--)
    {
        for(i = 1; i <= no_of_elements; i++)
        {
            if(P[i] == current)
            {
                break;
            }
        }
        
        //cout << "Current = " << current << " i = " << i << " \n";
        for(int j = i + 1; j <= current; j++)
        {
            if(P[j] <= i)
            {   //cout << "j = " << j << "\n";
                
                swap(P[i], P[j]);
                
                swaps.push_back(make_pair(i, j));
                
                cost += (j - i);
                
                i = j;
            }
        }
    }
    
    cout << cost << " " << swaps.size() << "\n";
    for(int i = 0; i < swaps.size(); i++)
    {
        cout << swaps[i].first << " " << swaps[i].second << "\n";
    }
    
    return 0;
}
