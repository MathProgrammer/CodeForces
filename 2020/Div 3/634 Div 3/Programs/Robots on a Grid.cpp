#include <iostream>
#include <vector>

using namespace std;

const int MAX_L = 25;

int rows, columns;
vector <string> colour;
vector <string> S;
vector <vector <int> > step(MAX_L);
vector <int> visited;

int label(int x, int y)
{
    return x*columns + y;
}

int is_bit_set(int n, int bit)
{
    return ((n&(1 << bit)) != 0);
}

int get_next(int x, int y)
{
    switch(S[x][y])
    {
        case 'U' : return label(x - 1, y);
        case 'R' : return label(x, y + 1);
        case 'L' : return label(x, y - 1);
        case 'D' : return label(x + 1, y);
    }
    
    return 0;
}

void dfs(int v)
{
    if(visited[v])
    {
        return;
    }
    
    visited[v] = true;
    
    int x = v/columns, y = v%columns;
    
    int next = get_next(x, y);
    //cout << "At " << v << " " << x << "," << y << " Next = " << next << "\n";
    step[0][v] = next;
    
    dfs(next);
}

void solve()
{
    cin >> rows >> columns;
    
    colour.resize(rows);
    for(int i = 0; i < rows; i++)
    {
        cin >> colour[i];
    }
    
    S.resize(rows);
    for(int i = 0; i < rows; i++)
    {
        cin >> S[i];
    }
    
    visited.resize(rows*columns, false);
    for(int i = 0; i < rows*columns; i++)
    {
        visited[i] = false;
    }
    
    for(int i = 0; i < MAX_L; i++)
    {
        step[i].resize(rows*columns);
    }
    
    for(int v = 0; v < rows*columns; v++)
    {
        if(!visited[v])
        {
            dfs(v);
        }
    }
    
    for(int l = 1; l < MAX_L; l++)
    {
        for(int i = 0; i < rows*columns; i++)
        {
            int previous_step = step[l - 1][i];
            
            //cout << "L = " << l << "Start at " << i/columns << "," << i%columns << " previous = " << previous_step/columns << "," << previous_step%columns <<" and finish at " << step[l - 1][previous_step]/columns << " " << step[l - 1][previous_step]%columns << "\n";
            
            step[l][i] = step[l - 1][previous_step];
        }
    }
    
    vector <int> black_starts(rows*columns);
    vector <int> white_starts(rows*columns);
    int total_steps = rows*columns;
    for(int i = 0; i < rows*columns; i++)
    {
        int finish = i;
        
        for(int bit = MAX_L - 1; bit >= 0; bit--)
        {
            if(is_bit_set(total_steps, bit))
            {
                finish = step[bit][finish];
            }
        }
        
        const char BLACK = '0', WHITE = '1';
        int start_x = i/columns, start_y = i%columns;
        if(colour[start_x][start_y] == BLACK)
        {
            black_starts[finish]++;
        }
        else
        {
            white_starts[finish]++;
        }
        
        //cout << "Start at " << start_x << "," << start_y << " and finish at " << finish/columns << " " << finish%columns << "\n";
    }
    
    int total = 0, black = 0;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            if(black_starts[label(i, j)] > 0)
            {
                total++;
                black++;
            }
            else if(white_starts[label(i, j)] > 0)
            {
                total++;
            }
        }
    }
    
    cout << total << " " << black << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
