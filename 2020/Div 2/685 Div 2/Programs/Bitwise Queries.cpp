#include <iostream>
#include <vector>

using namespace std;

void ask(int i, int j, string operation, int &result)
{
    cout << operation << " " << i << " " << j << "\n";
    cout.flush();
    
    cin >> result;
}

int main()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    vector <int> A(no_of_elements + 1);
    vector <int> xor_1(no_of_elements + 1);
    int and_12, and_23, and_13;
    
    ask(1, 2, "XOR", xor_1[2]);
    ask(1, 2, "AND", and_12);
    
    ask(1, 3, "XOR", xor_1[3]);
    ask(1, 3, "AND", and_13);
    
    ask(2, 3, "AND", and_23);
    int xor_23 = xor_1[2]^xor_1[3]; //(1^2)^(1^3) = 2^3
    
    int sum_12 = xor_1[2] + 2*and_12;
    int sum_23 = xor_23 + 2*and_23;
    int sum_13 = xor_1[3] + 2*and_13;
    
    A[1] = (sum_12 - sum_23 + sum_13)/2;
    A[2] = A[1]^xor_1[2];
    A[3] = A[1]^xor_1[3];
    
    for(int i = 4; i <= no_of_elements; i++)
    {
        ask(1, i, "XOR", xor_1[i]);
        
        A[i] = A[1]^xor_1[i];
    }
    
    cout << "! ";
    for(int i = 1; i <= no_of_elements; i++)
    {
        cout << A[i] << " ";
    }
    cout << "\n";
    cout.flush();
    
    return 0;
}
