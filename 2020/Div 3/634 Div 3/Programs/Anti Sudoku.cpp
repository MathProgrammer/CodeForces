#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    const int MAX_N = 9;
    vector <string> grid(MAX_N);
    for(int i = 0; i < MAX_N; i++)
    {
        cin >> grid[i];
    }
    
    /* Make it equivalent to this
     154873296
     386592714
     729641835
     863725149
     975314628
     412968357
     631457982
     598236471
     247189563*/
    
    /*Make it equivalent to this -
     154873396
     336592714
     729645835
     863725145
     979314628
     412958357
     631457992
     998236471
     247789563*/
    grid[0][6] = grid[0][5];
    grid[1][1] = grid[1][0];
    grid[2][5] = grid[2][8];
    grid[3][8] = grid[3][5];
    grid[4][2] = grid[4][0];
    grid[5][4] = grid[5][7];
    grid[6][7] = grid[6][8];
    grid[7][0] = grid[7][1];
    grid[8][3] = grid[8][2];
    
    for(int i = 0; i < MAX_N; i++)
    {
        cout << grid[i] << "\n";;
    }
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
