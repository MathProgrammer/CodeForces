#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    int a, b;
    string number;
    cin >> number >> a >> b;

    int no_of_numbers = number.size();

    vector <int> remainder_a_till(no_of_numbers);
    remainder_a_till[0] = (number[0] - '0')%a;

    for(int i = 1 ; number[i] != '\0'; i++)
    {
        remainder_a_till[i] = (10*remainder_a_till[i - 1] + number[i] - '0')%a;
    }


    vector <int> remainder_b_from(no_of_numbers);
    remainder_b_from[no_of_numbers - 1] = (number[no_of_numbers - 1] - '0')%b;

    for(int i = no_of_numbers - 2, ten_power = 10; i >= 0; i--)
    {
        remainder_b_from[i] = (ten_power*(number[i] - '0') + remainder_b_from[i + 1])%b;

        ten_power = (ten_power*10)%b;
    }

    int end_of_a = -1;
    for(int i = 0; i + 1 < no_of_numbers; i++)
    {
        if(remainder_a_till[i] == 0 && remainder_b_from[i + 1] == 0 && number[i + 1] != '0')
            end_of_a = i;
    }

    if(end_of_a == -1 || number[0] == '0')
    {
        printf("NO\n");
        return 0;
    }

    printf("YES\n");

    for(int i = 0; i <= end_of_a; i++) printf("%c", number[i]);

    printf("\n");

    for(int i = end_of_a + 1; i < no_of_numbers; i++) printf("%c", number[i]);

    return 0;
}
