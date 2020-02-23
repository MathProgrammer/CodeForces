#include <iostream>
#include <vector>

using namespace std;

int range(int max_1, int distance, int size, int &steps)
{
    int taken;
    
    if(distance*size <= steps)
    {
        taken = distance;
    }
    else
    {
        taken = steps/size;
    }
    
    steps -= taken*size;
    
    return taken;
}

int main()
{
    int rows, columns, steps;
    cin >> rows >> columns >> steps;
    
    if(steps > 4*rows*columns - 2*rows - 2*columns)
    {
        cout << "NO\n";
        
        return 0;
    }
    
    cout << "YES\n";
    vector < pair <int, string> > journey;
    
    for(int r = 1; r <= rows && steps > 0; r++)
    {
        int steps_taken;
        
        steps_taken = range(steps, columns - 1, 1, steps);
        
        if(steps_taken > 0)
        {
            journey.push_back(make_pair(steps_taken, "R"));
        }
        
        if(r < rows)
        {
            steps_taken = range(steps, columns - 1, 3, steps);
            
            if(steps_taken > 0)
            {
                journey.push_back(make_pair(steps_taken, "DUL"));
            }
            
            if(steps_taken < columns - 1 && steps < 3 && steps > 0)
            {
                switch(steps)
                {
                    case 2 : journey.push_back(make_pair(1, "DU")); steps -= 2; break;
                    case 1 : journey.push_back(make_pair(1, "D")); steps--; break;
                }
            }
            
            if(steps > 0)
            {
                journey.push_back(make_pair(1, "D"));
                
                steps--;
            }
            
            continue;
        }
        
        if(r == rows)
        {
            steps_taken = range(steps, columns - 1, 1, steps);
            
            if(steps_taken > 0)
            {
                journey.push_back(make_pair(steps_taken, "L"));
            }
            
            if(steps > 0)
            {
                steps_taken = range(steps, rows - 1, 1, steps);
                
                journey.push_back(make_pair(steps_taken, "U"));
            }
        }
    }

    cout << journey.size() << "\n";
    for(int i = 0; i < journey.size(); i++)
    {
        cout << journey[i].first << " " << journey[i].second << "\n";
    }
    return 0;
}
