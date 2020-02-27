#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
#define LEFT(n) (2*n)
#define RIGHT(n) (2*n + 1)
using namespace std;

struct hero
{
    int power, endurance;

    hero()
    {
        power = 0;
        endurance = 0;
    }

    hero(int P, int E)
    {
        P = power; E = endurance;
    }
};

int sort_by_endurance(const hero &A, const hero &B)
{
    if(A.endurance == B.endurance)
    {
        return (A.power < B.power);
    }
    
    return (A.endurance < B.endurance);
}

const int MAX_N = 2e5 + 5;
int max_tree[4*MAX_N], A[MAX_N];

void build(int n, int left, int right)
{
    if(left == right)
    {
        max_tree[n] = A[right];

        return;
    }

    int mid = (left + right)/2;

    build(LEFT(n), left, mid);
    build(RIGHT(n), mid + 1, right);

    max_tree[n] = max(max_tree[LEFT(n)], max_tree[RIGHT(n)]);
}

int get_max(int n, int left, int right, int query_left, int query_right)
{
    if(right < query_left || query_right < left)
        return 0;

    if(query_left <= left && right <= query_right)
        return max_tree[n];

    int mid = (left + right)/2;
    int left_max = get_max(LEFT(n), left, mid, query_left, query_right);
    int right_max = get_max(RIGHT(n), mid + 1, right, query_left, query_right);

    return max(left_max, right_max);
}

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;

    for(int i = 1; i <= no_of_elements; i++)
        cin >> A[i];
    
    build(1, 1, no_of_elements);

    int no_of_heroes;
    cin >> no_of_heroes;

    vector <hero> heroes(no_of_heroes + 1);
    for(int i = 1; i <= no_of_heroes; i++)
    {
        cin >> heroes[i].power >> heroes[i].endurance;
    }

    sort(all(heroes), sort_by_endurance);
    
    vector <int> max_power_for_endurance(no_of_elements + 5, 0);
    for(int i = 1; i <= no_of_heroes; i++)
    {
        max_power_for_endurance[heroes[i].endurance] = max(max_power_for_endurance[heroes[i].endurance], heroes[i].power);
    }
    
    for(int i = no_of_elements; i >= 1; i--)
    {
        max_power_for_endurance[i] = max(max_power_for_endurance[i + 1], max_power_for_endurance[i]);
        
        //cout << "Max Till " << i << " = " << max_power_for_endurance[i] << "\n";
    }
    
    int days = 0;
    for(int i = 1; i <= no_of_elements; days++)
    {
        if(max_power_for_endurance[no_of_elements - i + 1] >= get_max(1, 1, no_of_elements, i, no_of_elements))
        {
            days++;
            break;
        }
        
        int left = 0, right = no_of_elements - i + 1;
        
        while(right - left > 1)
        {   //cout << "L = " << left << " R = " << right << "\n";
            int mid = (left + right)/2;
            
            //cout << "Mid = " << mid << " Segment Max = [" << i <<
            //"," << i + mid - 1 << "] = " <<get_max(1, 1, no_of_elements, i, i + mid - 1) << " Endurance Max = " << max_power_for_endurance[mid] << "\n";
            if(max_power_for_endurance[mid] >= get_max(1, 1, no_of_elements, i, i + mid - 1))
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
        
        if(left == 0)
        {
            cout << "-1\n";
            
            return;
        }
        
        i = i + left; //cout << "i = " << i << "\n";
    }
    
    cout << days << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
