#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <ctime>

using namespace std;

int is_submask(long long mask, long long submask)
{
    return ((mask&submask) == submask);
}

int main()
{
    int no_of_students;
    cin >> no_of_students;

    map <long long, int> mask_frequency;
    vector <long long> mask(no_of_students + 1);
    for(int i = 1; i <= no_of_students; i++)
    {
        cin >> mask[i];

        mask_frequency[mask[i]]++;
    }

    vector <long long> skill_level(no_of_students + 1, 0);
    for(int i = 1; i <= no_of_students; i++)
    {
        cin >> skill_level[i];
    }

    vector <long long> distinct_masks;
    map <long long, int> selected;
    for(int i = 1; i <= no_of_students; i++)
    {
        if(mask_frequency[mask[i]] > 1 && !selected[mask[i]])
        {
            distinct_masks.push_back(mask[i]);

            selected[mask[i]] = true;
        }
    }

    for(int i = 1; i <= no_of_students; i++)
    {
        if(selected[mask[i]])
        {
            continue;
        }

        for(int j = 0; j < distinct_masks.size(); j++)
        {
            if(is_submask(distinct_masks[j], mask[i]))
            {
                selected[mask[i]] = true;

                break;
            }
        }
    }

    long long best_max_skill = 0;
    for(int i = 1; i <= no_of_students; i++)
    {
        if(selected[mask[i]])
        {
            best_max_skill += skill_level[i];
        }
    }

    cout << best_max_skill << "\n";
    return 0;
}


