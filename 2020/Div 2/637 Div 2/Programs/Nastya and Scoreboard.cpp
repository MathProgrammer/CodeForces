#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

const int MAX_N = 2015, DIGITS = 10, NO_OF_SEGMENTS = 7, oo = 1e9;
int is_possible[MAX_N][MAX_N];
vector <string> digits;

void hardcode()
{
    digits.push_back("1110111"); //0
    digits.push_back("0010010"); //1
    digits.push_back("1011101"); //2
    digits.push_back("1011011"); //3
    digits.push_back("0111010"); //4
    digits.push_back("1101011"); //5
    digits.push_back("1101111"); //6
    digits.push_back("1010010"); //7
    digits.push_back("1111111"); //8
    digits.push_back("1111011"); //9
}

int steps_to_convert(string &current, int number)
{
    int steps = 0;
    string ending = digits[number];
   
    for(int i = 0; i < NO_OF_SEGMENTS; i++)
    {
        if(current[i] == '1' && ending[i] == '0')
        {
            return oo;
        }
        
        if(current[i] == '0' && ending[i] == '1')
        {
            steps++;
        }
        
        //Otherwise current[i] = ending[i]
    }
    
    return steps;
}

int main()
{
    hardcode();
    
    int no_of_digits, switched_off_stick;
    cin >> no_of_digits >> switched_off_stick;
    
    vector <string> state(no_of_digits);
    for(int i = 0; i < no_of_digits; i++)
    {
        cin >> state[i];
    }
    
    memset(is_possible, false, sizeof(is_possible));
    
    is_possible[no_of_digits][0] = true;
    for(int i = no_of_digits - 1; i >= 0; i--)
    {
        for(int steps = 0; steps <= switched_off_stick; steps++)
        {
            for(int d = 0; d < DIGITS; d++)
            {
                int remaining_steps = steps - steps_to_convert(state[i], d);
                
                if(remaining_steps >= 0 && is_possible[i + 1][remaining_steps])
                {
                    //cout << "F(" << i << "," << steps << ") = for " << d << " is possible\n";
                    //cout << "Remaining Steps = " << remaining_steps << " And to Convert = " << steps_to_convert(state[i], d) << "\n";
                    is_possible[i][steps] = true;
                }
            }
        }
    }
    
    if(!is_possible[0][switched_off_stick])
    {
        cout << "-1\n";
        
        return 0;
    }
    
    int steps_remaining = switched_off_stick;
    string final_integer;
    for(int i = 0 ; i < no_of_digits; i++)
    {
        for(int d = 9; d >= 0; d--)
        {
            int steps_for_suffix = steps_remaining - steps_to_convert(state[i], d);
        
            if(steps_for_suffix >= 0 && is_possible[i + 1][steps_for_suffix])
            {
                final_integer.push_back('0' + d);
                
                steps_remaining -= steps_to_convert(state[i], d);
                
                break;
            }
        }
    }
    
    cout << final_integer << "\n";
    
    return 0;
}
