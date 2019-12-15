#include <iostream>
#include <vector>

using namespace std;

int max_3(int a, int b, int c)
{
    return max(a, max(b, c));
}

int main()
{
    const int oo = 1e9;
    
    int no_of_students, school_x, school_y;
    cin >> no_of_students >> school_x >> school_y;
    
    vector <int> X(no_of_students + 1);
    vector <int> Y(no_of_students + 1);
    
    int up = 0, right = 0, down = 0, left = 0;
    for(int i = 1; i <= no_of_students; i++)
    {
        int x, y;
        cin >> x >> y;
        
        up += (y > school_y);
        down += (y < school_y);
        left += (x < school_x);
        right += (x > school_x);
    }
    
    if(up >= max_3(left, right, down))
    {
        cout << up << "\n";
        cout << school_x << " " << school_y + 1 << "\n";
    }
    else if(left >= max_3(up, down, right))
    {
        cout << left << "\n";
        cout << school_x - 1 << " " << school_y << "\n";
    }
    else if(right >= max_3(up, down, left))
    {
        cout << right << "\n";
        cout << school_x + 1 << " " << school_y << "\n";
    }
    else if(down >= max_3(left, right, up))
    {
        cout << down << "\n";
        cout << school_x << " " << school_y - 1 << "\n";
    }
    
    return 0;
}
