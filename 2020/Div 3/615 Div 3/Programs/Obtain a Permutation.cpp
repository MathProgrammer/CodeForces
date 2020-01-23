#include <iostream>
#include <vector>

using namespace std;

int rows, columns;
vector <vector <int> > A;

long long ceil(long long n, long long d)
{
    return (n/d + (n%d != 0));
}

long long calculate_best_cost(int column_no)
{
    vector <long long> rotation_cost(rows + 1, 0);
    for(int rotations = 0; rotations < rows; rotations++)
    {
        rotation_cost[rotations] = rotations + rows;
        //cout << "Cost " << rotations << " = " << rotation_cost[rotations] << "\n";
    }
    
    for(int i = 1; i <= rows; i++)
    {
        if(A[i][column_no]%columns != column_no%columns)
        {
            continue;
        }
        
        int best_place = ceil(A[i][column_no], columns);
        
        if(best_place > rows)
        {
            continue;
        }
        
        int best_rotation;
        
        if(best_place <= i)
        {
            best_rotation = (i - best_place);
        }
        else
        {
            best_rotation = (i - 1) + (rows - best_place + 1);
        }
        //cout << i << " " << column_no << " Best place = " << best_place << " " << best_rotation << "\n";
        rotation_cost[best_rotation]--;
        //cout << "Cost of " << best_rotation << " = " << rotation_cost[best_rotation] << "\n";
    }
    
    long long best_cost = rotation_cost[0];
    for(int rotations = 1; rotations < rows; rotations++)
    {
        best_cost = min(best_cost, rotation_cost[rotations]);
    }
    //cout << "Column " << column_no  << " = " << best_cost << "\n";
    return best_cost;
}

int main()
{
    cin >> rows >> columns;
    
    A.resize(rows + 1);
    for(int i = 0; i <= rows; i++)
    {
        A[i].resize(columns + 1);
    }
    
    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= columns; j++)
        {
            cin >> A[i][j];
        }
    }
    
    long long moves = 0;
    for(int i = 1; i <= columns; i++)
    {
        moves += calculate_best_cost(i);
    }
    
    cout << moves << "\n";
    
    return 0;
}
