#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int is_possible(vector <int> &strength, int no_of_piles)
{
    priority_queue <int> pile_tops;

    int box_ptr = strength.size() - 1;

    for(int i = 1; i <= no_of_piles; i++)
        pile_tops.push(strength[box_ptr--]);

    while(box_ptr >= 0)
    {
        int strongest_pile = pile_tops.top();
        pile_tops.pop();

        if(strongest_pile == 0) return false;

        int next_box = strength[box_ptr];
        pile_tops.push(min(strongest_pile - 1, next_box));

        box_ptr--;
    }

    return true;
}

int main()
{
    int no_of_boxes;
    scanf("%d", &no_of_boxes);

    vector <int> strength(no_of_boxes);
    for(int i = 0; i < no_of_boxes; i++) scanf("%d", &strength[i]);

    sort(all(strength));

    int left = 1, right = no_of_boxes, answer;
    while(left <= right)
    {
        int mid = (left + right) >> 1;

        if(is_possible(strength, mid))
        {
            if(mid == 1 || !is_possible(strength, mid - 1))
            {
                answer = mid;
                break;
            }
            else
            {
                right = mid - 1;
            }
        }
        else
        {
            left = mid + 1;
        }
    }

    printf("%d", answer);
    return 0;
}
