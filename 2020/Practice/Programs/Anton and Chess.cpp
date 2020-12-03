#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int check(int x, vector <pair <long long, char> > &A, char attacker_1, char queen = 'Q')
{
    pair <long long, char> king = make_pair(x, 'K');
    
    int next = upper_bound(all(A), king) - A.begin();
    
    if(next < A.size() && (A[next].second == attacker_1 || A[next].second == queen))
    {
        return true;
    }
    
    int before = next - 1;
    
    if(before >= 0 && (A[before].second == attacker_1 || A[before].second == queen))
    {
        return true;
    }
    
    return false;
}

int main()
{
    int no_of_black_pieces;
    cin >> no_of_black_pieces;
    
    long long king_x, king_y;
    cin >> king_x >> king_y;
    
    long long king_diagonal = king_x - king_y;
    long long king_antidiagonal = king_x + king_y;
    
    vector <pair <long long, char> > row, column, diagonal, anti_diagonal;
    for(int i = 1; i <= no_of_black_pieces; i++)
    {
        char piece;
        long long x, y;
        cin >> piece >> x >> y;
        
        if(x == king_x)
        {
            row.push_back(make_pair(y, piece));
        }
        if(y == king_y)
        {
            column.push_back(make_pair(x, piece));
        }
        
        if(x - y == king_diagonal)
        {
            diagonal.push_back(make_pair(x + y, piece));
        }
        if(x + y == king_antidiagonal)
        {
            anti_diagonal.push_back(make_pair(x - y, piece));
        }
    }
    
    sort(all(row));
    sort(all(column));
    sort(all(diagonal));
    sort(all(anti_diagonal));
    
    int in_check = false;
    
    in_check = (check(king_y, row, 'R') ||
                check(king_x, column, 'R') ||
                check(king_antidiagonal, diagonal, 'B') ||
                check(king_diagonal, anti_diagonal,'B') );
    
    cout << (in_check ? "YES" : "NO") << "\n";
    return 0;
}
