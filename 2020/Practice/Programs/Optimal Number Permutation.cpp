#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    vector <int> A(2*no_of_elements + 1);
    for(int front = 1, back = no_of_elements, odd = 1; odd <= no_of_elements; front++, back--, odd += 2)
    {
        A[front] = A[back] = odd;
    }
    
    for(int front = no_of_elements + 1, back = 2*no_of_elements - 1, even = 2; even <= no_of_elements; front++, back--, even += 2)
    {
        A[front] = A[back] = even;
    }
    
    for(int i = 1; i <= 2*no_of_elements; i++)
    {
        if(A[i] == 0)
        {
            A[i] = no_of_elements;
        }
    }
    
    for(int i = 1; i <= 2*no_of_elements; i++)
    {
        cout << A[i] << " ";
    }
    
    cout << "\n";
    
    return 0;
}
