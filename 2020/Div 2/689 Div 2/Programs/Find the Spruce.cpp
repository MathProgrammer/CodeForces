#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int rows, columns;
    cin >> rows >> columns;
    
    vector <string> grid(rows);
    for(int i = 0; i < rows; i++)
    {
        cin >> grid[i];
    }
    
    vector <vector <int> > height(rows, vector <int> (columns, 0));
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            if(grid[i][j] == '*')
            {
                height[i][j] = (i == 0 ? 1 : height[i - 1][j] + 1);
            }
            
        }
    }
    
    vector <vector <int> > left_spruce(rows, vector <int> (columns, 0));
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            left_spruce[i][j] = height[i][j];
            
            if(j == 0)
            {
                left_spruce[i][j] = min(left_spruce[i][j], 1);
            }
            
            if(j > 0)
            {
                left_spruce[i][j] = min(left_spruce[i][j], left_spruce[i][j - 1] + 1);
            }
        }
    }
    
    vector <vector <int> > right_spruce(rows, vector <int> (columns, 0));
    for(int i = 0; i < rows; i++)
    {
        for(int j = columns - 1; j >= 0; j--)
        {
            right_spruce[i][j] = height[i][j];
            
            if(j == columns - 1)
            {
                right_spruce[i][j] = min(right_spruce[i][j], 1);
            }
            
            if(j < columns - 1)
            {
                right_spruce[i][j] = min(right_spruce[i][j], right_spruce[i][j + 1] + 1);
            }
        }
    }
    
    long long total_spruce = 0;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            int spruce_here = min(right_spruce[i][j], left_spruce[i][j]);
            
            total_spruce += spruce_here;
        }
    }
    
    cout << total_spruce << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
