#include <cstdio>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int no_of_pearls;
    scanf("%d", &no_of_pearls);

    set <int> current_segment_pearls;
    vector <pair <int, int> > segment;
    int left = 1;

    for(int right = 1; right <= no_of_pearls; right++)
    {
        int pearl_type;
        scanf("%d", &pearl_type);

        if(current_segment_pearls.count(pearl_type) == 1)
        {
            segment.push_back(make_pair(left, right));
            current_segment_pearls.clear();

            left = right + 1;
        }
        else
        {
            current_segment_pearls.insert(pearl_type);
        }
    }

    if(segment.size() == 0)
        printf("-1\n");
    else
    {
        segment.back().second = max(segment.back().second, no_of_pearls);

        printf("%u\n", segment.size());
        for(int i = 0; i < segment.size(); i++)
            printf("%d %d\n", segment[i].first, segment[i].second);
    }

    return 0;
}
