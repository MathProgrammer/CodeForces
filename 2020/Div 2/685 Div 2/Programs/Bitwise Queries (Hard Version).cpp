#include <iostream>
#include <vector>
#include <map>

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
    
    vector <int> A(no_of_elements + 1, -1);
    vector <int> xor_1(no_of_elements + 1, 0);
    for(int i = 2; i <= no_of_elements; i++)
    {
        ask(1, i, "XOR", xor_1[i]);
    }
    
    int and_12 = -1, and_23 = -1, and_13 = -1;
    int xor_12 = -1 , xor_13 = -1, xor_23 = -1;
    int second = 0, third = 0;
    
    map <int, int> last_xor_occurence;
    
    for(int i = 1; i <= no_of_elements; i++)
    {
        //All Elements Different, At least one pair XOR = n - 1, n = 2^p
        if(xor_1[i] == no_of_elements - 1)
        {
            second = i;
            third = (i == 2 ? 3 : 2);
            
            xor_12 = xor_1[second];
            xor_13 = xor_1[third];
            xor_23 =  xor_1[second]^xor_1[third];
            
            and_12 = 0;
            ask(second, third, "AND", and_23);
            ask(1, third, "AND", and_13);
            break;
        }
        
        //Two Equal Elements
        if(last_xor_occurence[xor_1[i]] != 0)
        {
            ask(last_xor_occurence[xor_1[i]], i, "AND", A[i]);
            A[1] = A[i]^xor_1[i];
            
            break;
        }
        
        last_xor_occurence[xor_1[i]] = i;
    }
    
    if(second != 0 && third != 0)
    {
        int sum_12 = xor_12 + 2*and_12;
        int sum_23 = xor_23 + 2*and_23;
        int sum_13 = xor_13 + 2*and_13;

        A[1] = (sum_12 - sum_23 + sum_13)/2;
    }
    
    for(int i = 2; i <= no_of_elements; i++)
    {
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
