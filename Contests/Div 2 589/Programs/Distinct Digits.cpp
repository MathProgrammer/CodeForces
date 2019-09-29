#include <iostream>
#include <vector>

using namespace std;

int distinct_digits(int n)
{
   vector <int> frequency(10, 0);

   while(n > 0)
   {
       if(frequency[n%10] > 0)
            return false;

       frequency[n%10]++;

       n /= 10;
   }

   return true;
}

int main()
{
    int left, right;
    cin >> left >> right;

    for(int i = left; i <= right; i++)
    {
        if(distinct_digits(i))
        {
            cout << i << endl;

            return 0;
        }
    }

    cout << "-1\n";
    return 0;
}
