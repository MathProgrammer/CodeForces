#include <cstdio>
#include <vector>
#include <algorithm>

#define all(v) (v).begin() + 1, (v).end()
using namespace std;

struct info
{
    int money, friendship;
};

int sort_by_money(const info &A, const info &B)
{
    return (A.money < B.money);
}

int main()
{
    int no_of_friends, difference;
    scanf("%d %d", &no_of_friends, &difference);

    vector <info> friends(no_of_friends + 1);
    for(int i = 1; i <= no_of_friends; i++)
        scanf("%d %d", &friends[i].money, &friends[i].friendship);

    sort(all(friends), sort_by_money);

    long long maximum_friendship = 0, current_friendship = 0;
    int left = 1, right = 1;

    while(right <= no_of_friends)
    {
         if(friends[right].money - friends[left].money < difference)
        {
            current_friendship += friends[right].friendship;
            right++;
        }
        else
        {
            current_friendship -= friends[left].friendship;
            left++;
        }

        maximum_friendship = max(maximum_friendship, current_friendship);
    }

    printf("%I64d\n", maximum_friendship);
    return 0;
}
