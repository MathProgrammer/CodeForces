#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int no_of_lamps;
    cin >> no_of_lamps;
    
    vector <int> index(no_of_lamps);
    for(int i = 1; i < no_of_lamps; i++)
    {
        cin >> index[i];
    }
    
    vector <int> used(no_of_lamps + 1, false);
    int root = index[1];
    int current = no_of_lamps;
    
    cout << root << "\n";
    for(int i = 1; i < no_of_lamps; i++)
    {
        used[index[i]] = true;
        
        while(used[current])
        {
            current--;
        }
        
        if(i == no_of_lamps - 1 || used[index[i + 1]])
        {
            cout << index[i] << " " << current << "\n";
            
            used[current] = true;
        }
        else
        {
            cout << index[i] << " " << index[i + 1] << "\n";
        }
    }
    return 0;
}
