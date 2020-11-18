#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int flip(int x)
{
    return (1 - x);
}

void perform(vector <vector <int> > &M, vector <pair <int, int> > &op, int i, int j)
{
    op.push_back(make_pair(i, j));
    
    M[i][j] = flip(M[i][j]);
}

void perform(vector <vector <int> > &M, vector <pair <int, int> > &op, pair <int, int> P)
{
    perform(M, op, P.first, P.second);
}

/*x x
    x*/
void flip_corner_L(vector <vector <int> > &M, vector <pair <int, int> > &op, int i, int j)
{
    perform(M, op, i, j);
    
    perform(M, op, i - 1, j);
    
    perform(M, op, i - 1, j - 1);
}

/*x x
    x*/
void flip_down_corner_L(vector <vector <int> > &M, vector <pair <int, int> > &op, int i, int j)
{
    perform(M, op, i, j);
    
    perform(M, op, i + 1, j);
    
    perform(M, op, i, j - 1);
}

/* x
   x x */
void flip_down_L(vector <vector <int> > &M, vector <pair <int, int> > &op, int i, int j)
{
    perform(M, op, i, j);
    
    perform(M, op, i, j + 1);
    
    perform(M, op, i - 1, j);
}

/* x
   x x */
void flip_down_back_L(vector <vector <int> > &M, vector <pair <int, int> > &op, int i, int j)
{
    perform(M, op, i, j);
    
    perform(M, op, i, j - 1);
    
    perform(M, op, i - 1, j - 1);
}

/*x x
  x */
void flip_up_L(vector <vector <int> > &M, vector <pair <int, int> > &op, int i, int j)
{
    perform(M, op, i, j);
    
    perform(M, op, i - 1, j);
    
    perform(M, op, i - 1, j + 1);
}

/*x x
  x */
void flip_down_up_L(vector <vector <int> > &M, vector <pair <int, int> > &op, int i, int j)
{
    perform(M, op, i, j);
    
    perform(M, op, i, j - 1);
    
    if(i == 1)
    {
        perform(M, op, i + 1, j - 1);
    }
    else
    {
        perform(M, op, i - 1, j - 1);
    }
}


void solve_3(vector <vector <int> > &M, vector <pair <int, int> > &op, vector <pair <int, int> > &S)
{
    for(int i = 0; i < S.size(); i++)
    {
        if(M[S[i].first][S[i].second] == 1)
        {
            perform(M, op, S[i]);
        }
    }
}

void solve_2(vector <vector <int> > &M, vector <pair <int, int> > &op, vector <pair <int, int> > &S)
{
    int frequency_1 = 0;
    
    for(int i = 0; i < S.size(); i++)
    {
        if(M[S[i].first][S[i].second] == 1)
        {
            if(frequency_1 == 0)
            {
                perform(M, op, S[i]);
            }
            
            frequency_1++;
        }
        else
        {
            perform(M, op, S[i]);
        }
    }
}

void solve_1(vector <vector <int> > &M, vector <pair <int, int> > &op, vector <pair <int, int> > &S)
{
    int r_1, c_1;
    
    for(int i = 0; i < S.size(); i++)
    {
        if(M[S[i].first][S[i].second] == 1)
        {
            r_1 = S[i].first; c_1 = S[i].second;
        }
    }
    
    for(int i = 0; i < S.size(); i++)
    {
        if(S[i].first == r_1 || S[i].second == c_1)
        {
            perform(M, op, S[i]);
        }
    }
}

void solve_4(vector <vector <int> > &M, vector <pair <int, int> > &op, vector <pair <int, int> > &S)
{
    for(int i = 0; i < 3; i++)
    {
        perform(M, op, S[i]);
    }
}

void get(vector <vector <int> > &M, vector <pair <int, int> > &op, vector <pair <int, int> > &S)
{
    int one_count = 0;
    for(int i = 0; i < S.size(); i++)
    {
        one_count += (M[S[i].first][S[i].second] == 1);
    }
    
    switch(one_count)
    {
        case 4 : solve_4(M, op, S);
        case 1 : solve_1(M, op, S);
        case 2 : solve_2(M, op, S);
        case 3 : solve_3(M, op, S);
    }
}

void solve()
{
    int rows, columns;
    scanf("%d %d", &rows, &columns);
    
    vector <vector <int> > M(rows + 1, vector <int> (columns + 1));
    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= columns; j++)
        {
            scanf("%1d", &M[i][j]);
            //printf("%d\n", M[i][j]);
        }
    }
    
    vector <pair <int, int> > operations;
    
    if(rows%2 == 1)
    {
        for(int j = 1; j <= columns; j++)
        {
            if(M[rows][j] == 1)
            {
                if(j == columns)
                {
                    flip_corner_L(M, operations, rows, j);
                }
                else if(M[rows][j + 1] == 1)
                {
                    flip_down_L(M, operations, rows, j);
                }
                else
                {
                    flip_up_L(M, operations, rows, j);
                }
            }
        }
    }
    
    if(columns%2 == 1)
    {
        for(int i = 1; i <= rows; i++)
        {
            if(M[i][columns] == 1)
            {
                if(i == rows)
                {
                    flip_down_back_L(M, operations, i, columns);
                }
                else if(M[i + 1][columns] == 1)
                {
                    flip_down_corner_L(M, operations, i, columns);
                }
                else
                {
                    flip_down_up_L(M, operations, i, columns);
                }
            }
        }
    }
    
    for(int i = 1; i + 1 <= rows; i += 2)
    {
        for(int j = 1; j + 1 <= columns; j += 2)
        {
            vector <pair <int, int> > squares;
            
            int next_r = i + 1, next_c = j + 1;
            
            squares.push_back(make_pair(i, j));
            squares.push_back(make_pair(i + 1, j));
            squares.push_back(make_pair(i, j + 1));
            squares.push_back(make_pair(i + 1, j + 1));
            
            get(M, operations, squares);
        }
    }
    
    printf("%d\n", operations.size()/3);
    
    for(int i = 0; i < operations.size(); i++)
    {
        printf("%d %d ", operations[i].first, operations[i].second);
        
        if((i + 1)%3 == 0)
        {
            printf("\n");
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
