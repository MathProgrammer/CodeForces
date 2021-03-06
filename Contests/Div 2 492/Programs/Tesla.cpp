#include <iostream>
#include <vector>

using namespace std;

const int MAX_ROWS = 4, MAX_COLUMNS = 55, MAX_CARS = 101;
int parking_lot[MAX_ROWS + 1][MAX_COLUMNS];

struct Move
{
    int index, row, column;
    
    Move(){};
    
    Move(int I, int R, int C)
    {
        index = I; row = R; column = C;
    }
};

void park(vector <Move> &Moves, int no_of_columns)
{
    for(int column = 1; column <= no_of_columns; column++)
    {
        if(parking_lot[2][column] != 0 && parking_lot[2][column] == parking_lot[1][column])
        {
            Moves.push_back(Move(parking_lot[2][column], 1, column));
            
            parking_lot[2][column] = 0;
        }
        
        if(parking_lot[3][column] != 0 && parking_lot[3][column] == parking_lot[4][column])
        {
            Moves.push_back(Move(parking_lot[3][column], 4, column));
            
            parking_lot[3][column] = 0;
        }
    }
}

void rotate(vector <Move> &Moves, int no_of_columns)
{
    int start_row = -1, start_column = -1;

    for(int r = 2; r <= 3 && start_row == -1; r++)
    {
        for(int c = 1; c <= no_of_columns; c++)
        {
            if(parking_lot[r][c] == 0)
            {
                int next_r = r, next_c = c;
                
                if(r == 2)
                {
                    if(c == no_of_columns)
                    {
                        next_c = no_of_columns;
                        next_r = r + 1;
                    }
                    else
                    {
                        next_c = c + 1;
                    }
                }
                else if(r == 3)
                {
                    if(c == 1)
                    {
                        next_c = 1;
                        next_r = r - 1;
                    }
                    else
                    {
                        next_c = c - 1;
                    }
                }
                
                if(parking_lot[next_r][next_c] != 0)
                {
                    start_row = r;
                    start_column = c;
                    break;
                }
            }
        }
    }
    
    if(start_row == -1 || start_column == -1)
    {
        return;
    }
    
    int r = start_row, c = start_column;
    
    while(true)
    {
        int next_r = r, next_c = c;
        
        if(r == 2)
        {
            if(c == no_of_columns)
            {
                next_c = no_of_columns;
                next_r = r + 1;
            }
            else
            {
                next_c = c + 1;
            }
        }
        else if(r == 3)
        {
            if(c == 1)
            {
                next_c = 1;
                next_r = r - 1;
            }
            else
            {
                next_c = c - 1;
            }
        }
        
        if(next_r == start_row && next_c == start_column)
        {
            break;
        }
        
        if(parking_lot[next_r][next_c] != 0)
        {
            Moves.push_back(Move(parking_lot[next_r][next_c], r, c));
            
            parking_lot[r][c] = parking_lot[next_r][next_c];
            
            parking_lot[next_r][next_c] = 0;
        }
        
        r = next_r; c = next_c;
    }
}

int check_empty(int no_of_columns)
{
    for(int r = 2; r <= 3; r++)
    {
        for(int c = 1; c <= no_of_columns; c++)
        {
            if(parking_lot[r][c] != 0)
            {
                return false;
            }
        }
    }
    
    return true;
}

void print()
{
    cout << "Parking Lot = \n";
    
    for(int i = 1; i <= MAX_ROWS; i++)
    {
        for(int j = 1; j <= 4; j++)
        {
            cout << parking_lot[i][j] << " ";
        }
        
        cout << "\n";
    }
}

int main()
{
    int no_of_columns, no_of_cars;
    cin >> no_of_columns >> no_of_cars;
    
    for(int i = 1; i <= MAX_ROWS; i++)
    {
        for(int j = 1; j <= no_of_columns; j++)
        {
            cin >> parking_lot[i][j];
        }
    }
    
    vector <Move> Moves;
    for(int rotations = 1; rotations <= 2*no_of_columns; rotations++)
    {
        park(Moves, no_of_columns);
        
        //print();
        
        rotate(Moves, no_of_columns); //print();
    }
    
    if(!check_empty(no_of_columns))
    {
        cout << "-1\n";
        
        return 0;
    }
    
    cout << Moves.size() << "\n";
    for(int i = 0; i < Moves.size(); i++)
    {
        cout << Moves[i].index << " " << Moves[i].row << " " << Moves[i].column << "\n";
    }
    
    return 0;
}
