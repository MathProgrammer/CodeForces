#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

struct event
{
    int time, start, end, is_entry;
    
    event(){}
    
    event(int T, int S, int E, int is_E)
    {
        time = T; start = S; end = E; is_entry = is_E;
    }
    
    int operator <(const event &E)
    {
        if(time == E.time)
        {
            return (is_entry < E.is_entry);
        }
        
        return (time < E.time);
    }
};

int same_intersections(vector <int> start_a, vector <int> end_a, vector <int> start_b,  vector <int> end_b)
{
    multiset <int> starts, ends;
    
    vector <event> events;
    for(int i = 0; i < start_a.size(); i++)
    {
        events.push_back(event(start_a[i], start_b[i], end_b[i], true));
        events.push_back(event(end_a[i] + 1, start_b[i], end_b[i], false));
    }
    
    sort(all(events));
    
    for(int i = 0; i < events.size(); i++)
    {
        if(events[i].is_entry)
        {
            if(!starts.empty())
            {
                int last_start = *starts.rbegin();
                int earliest_end = *ends.begin();
                
                if(earliest_end < events[i].start || last_start > events[i].end)
                {
                    return false;
                }
                
                starts.insert(events[i].start);
                ends.insert(events[i].end);
            }
        }
        else
        {
            starts.erase(starts.find(events[i].start));
            ends.erase(ends.find(events[i].end));
        }
    }
    
    return true;
}

int main()
{
    int no_of_lectures;
    cin >> no_of_lectures;
    
    vector <int> start_a(no_of_lectures), start_b(no_of_lectures), end_a(no_of_lectures), end_b(no_of_lectures);
    for(int i = 0; i < no_of_lectures; i++)
    {
        cin >> start_a[i] >> end_a[i] >> start_b[i] >> end_b[i];
    }
    
    cout << (same_intersections(start_a, end_a, start_b, end_b) && same_intersections(start_b, end_b, start_a, end_a) ? "YES\n" : "NO\n");
    
    return 0;
}
