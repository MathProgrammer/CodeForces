#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
#define min(a, b) (a < b ? a : b)
using namespace std;

void compute(vector <long long> &lucky_numbers, long long last_lucky_number)
{
    lucky_numbers.push_back(last_lucky_number);

    if(last_lucky_number > 1e10)
        return ;

    compute(lucky_numbers, last_lucky_number*10 + 4);
    compute(lucky_numbers, last_lucky_number*10 + 7);
}

long long get_answer(vector <long long> &lucky_numbers, int limit)
{
    long long answer = 0;

    for(int i = 1; i < lucky_numbers.size() && lucky_numbers[i - 1] < limit; i++)
    {
        long long next_lucky_number = lucky_numbers[i];
        long long range = min(limit, lucky_numbers[i]) - lucky_numbers[i - 1];

        answer += next_lucky_number*range;
    }

    return answer;
}

int main()
{
    vector <long long> lucky_numbers;
    compute(lucky_numbers, 0);

    sort(all(lucky_numbers));

    int left, right;
    scanf("%d %d", &left, &right);

    long long answer = get_answer(lucky_numbers, right) - get_answer(lucky_numbers, left - 1);
    printf("%I64d\n", answer);

    return 0;
}
