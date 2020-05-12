#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int no_of_sticks;
    cin >> no_of_sticks;
    
    vector <int> A(no_of_sticks + 1);
    for(int i = 1; i <= no_of_sticks; i++)
    {
        cin >> A[i];
    }
    
    long long no_of_triangles = 0;
    int remaining_sticks = 0;
    for(int highest = 1; highest <= no_of_sticks; highest++)
    {
        int triangles_here = min(remaining_sticks, A[highest]/2);
        
        no_of_triangles += triangles_here;
        
        A[highest] -= 2*triangles_here;
        remaining_sticks = remaining_sticks - triangles_here;
        
        no_of_triangles += A[highest]/3;
        A[highest] %= 3;
        
        remaining_sticks += A[highest];
    }
    
    cout << no_of_triangles << "\n";
    return 0;
}
