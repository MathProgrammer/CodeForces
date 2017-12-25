#include <bits/stdc++.h>

#define all(v) (v).begin(), (v).end()
using namespace std;

struct code
{
    int is_first_digit, coefficient;

    code(){
        is_first_digit = false, coefficient = 0;
    }
};

int compare(const code &A, const code &B)
{
    return (A.coefficient < B.coefficient);
}

int main()
{
    const int NO_OF_DIGITS = 10;
    vector <code> letter(NO_OF_DIGITS);

    int no_of_numbers;
    scanf("%d", &no_of_numbers);

    while(no_of_numbers--)
    {
        string number;
        cin >> number;

        letter[number[0] - 'a'].is_first_digit = true;

        int power_of_10 = 1;

        for(int i = number.size() - 1; i >= 0; i--)
        {
            letter[number[i] - 'a'].coefficient += power_of_10;
            power_of_10 *= 10;
        }
    }

    sort(all(letter), compare);

    vector <int> assigned(NO_OF_DIGITS, false);

    int sum = 0;

    for(int i = NO_OF_DIGITS - 1; i >= 0; i--)
    {
        int digit = (letter[i].is_first_digit ? 1 : 0);

        while(assigned[digit])
            digit++;

        assigned[digit] = true;

        sum += letter[i].coefficient*digit;
    }

    printf("%d\n", sum);
    return 0;
}
