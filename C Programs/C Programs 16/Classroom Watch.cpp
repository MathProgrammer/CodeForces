#include <cstdio>
#include <vector>

using namespace std;

int digit_sum(int n)
{
    int sum = 0;

    while(n > 0)
    {
        sum += n%10;
        n = n/10;
    }

    return sum;
}

int main()
{
    int n;
    scanf("%d", &n);

    const int MAX_DIGIT_SUM = 81;
    int x = max(0, n - MAX_DIGIT_SUM);

    vector <int> answer;
    while(x <= n)
    {
        if(x + digit_sum(x) == n)
            answer.push_back(x);

        x++;
    }

    printf("%d\n", answer.size());
    for(int i = 0; i < answer.size(); i++)
        printf("%d ", answer[i]);

    return 0;
}
