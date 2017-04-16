#include <stdio.h>
#include <math.h>

long long find_solution(long long);
int sum_of_digits(long long);

int main()
{
    long long n, solution;
    scanf("%I64d",&n);

    solution = find_solution(n);
    printf("%I64d\n",solution);
    return 0;
}

//Find smallest x, such that x^2 + s(x)*x = n, where s(x) is the sum of digits of x
long long find_solution(long long n)
{
    long long x;
    long long solution = -1;
    const int MAX_DIGIT_SUM = 81; //x^2 can be 10^18 at most, x can be 10^9 at most. s(x) can be s(10^9 -1) = 9*9 = 81 at most.

    x = (int)sqrt(n);
    while(x*x + MAX_DIGIT_SUM*x >= n)
    {
        if(x*x + sum_of_digits(x)*x == n)
        {
            solution = x;
            break;
        }
        x--;
    }

    return solution;
}

int sum_of_digits(long long num)
{
    long long temp;
    int sum = 0;
    for(temp = num; temp > 0; temp = temp/10)
    {
        sum = sum + temp%10;
    }
    return sum;
}
