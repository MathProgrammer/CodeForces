#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int no_of_robots;
    cin >> no_of_robots;
    
    vector <int> A(no_of_robots + 1);
    for(int i = 1; i <= no_of_robots; i++)
    {
        cin >> A[i];
    }
    
    vector <int> B(no_of_robots + 1);
    for(int i = 1; i <= no_of_robots; i++)
    {
        cin >> B[i];
    }
    
    int a_points = 0, b_points = 0;
    for(int i = 1; i <= no_of_robots; i++)
    {
        if(A[i] != 0 && B[i] == 0)
        {
            a_points++;
        }
        else if(A[i] == 0 && B[i] != 0)
        {
            b_points++;
        }
    }
    
    int answer = 0;
    
    if(a_points == 0)
    {
        answer = -1;
    }
    else if(a_points > b_points)
    {
        answer = 1;
    }
    else
    {
        answer = (b_points/a_points) + 1;
    }
    
    cout << answer << "\n";
    return 0;
}
