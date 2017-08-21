#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int no_of_people;
    scanf("%d", &no_of_people);

    vector <int> present_giver_of(no_of_people + 1);
    for(int i = 1; i <= no_of_people; i++)
    {
        int gift_receiver;
        scanf("%d", &gift_receiver);

        present_giver_of[gift_receiver] = i;
    }

    for(int i = 1; i <= no_of_people; i++)
        printf("%d ", present_giver_of[i]);

    return 0;
}
