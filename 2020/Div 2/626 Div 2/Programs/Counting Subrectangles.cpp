#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int rows, columns, area;
    cin >> rows >> columns >> area;
    
    vector <int> A(rows + 5, 0);
    for(int i = 1; i <= rows; i++)
    {
        cin >> A[i];
    }
    
    vector <int> B(columns + 5, 0);
    for(int i = 1; i <= columns; i++)
    {
        cin >> B[i];
    }
    
    map <int, int> row_frequency;
    vector <int> row_segments;
    row_segments.push_back(0);
    int segment = 0;
    for(int i = 1; i <= rows + 1; i++)
    {
        if(A[i] == 0 || i == rows + 1)
        {
            row_frequency[segment]++;
            
            row_segments.push_back(segment);
            
            segment = 0;
            
            continue;
        }
        
        segment++;
    }
    
    sort(all(row_segments));
    
    vector <long long> row_sum(row_segments.size(), 0);
    for(int i = 1; i < row_segments.size(); i++)
    {
        row_sum[i] = row_sum[i - 1] + row_segments[i];
    }
    
    map <int, int> column_frequency;
    vector <int> column_segments;
    column_segments.push_back(0);
    segment = 0;
    for(int i = 1; i <= columns + 1; i++)
    {
        if(B[i] == 0 || i == columns + 1)
        {
            column_frequency[segment]++;
            
            column_segments.push_back(segment);
            
            segment = 0;
            
            continue;
        }
        
        segment++;
    }
    
    sort(all(column_segments));
    
    vector <long long> column_sum(column_segments.size(), 0);
    for(int i = 1; i < column_segments.size(); i++)
    {
        column_sum[i] = column_sum[i - 1] + column_segments[i];
    }
    
    long long no_of_subrectangles = 0;
    for(long long i = 1; i*i <= area; i++)
    {
        if(area%i == 0)
        {
            long long f1 = i, f2 = area/i;
            
            long long row_contribution = 0;
            
            if(f1 <= row_segments.back())
            {
                int j = upper_bound(all(row_segments), f1 - 1) - row_segments.begin();
                
                row_contribution = (row_sum.back() - row_sum[j - 1]) -
                    (row_segments.size() - 1 - (j - 1))*(f1 - 1);
                
                //cout << "Sum = " << (row_sum.back() - row_sum[j - 1]) << " - "
                 //<< (row_segments.size() - 1 - (j - 1))*(f2 - 1) << "\n";
            }
            
            long long column_contribution = 0;
            
            if(f2 <= column_segments.back())
            {
                int j = upper_bound(all(column_segments), f2 - 1) - column_segments.begin();
                
                column_contribution = (column_sum.back() - column_sum[j - 1]) -
                    (column_segments.size() - 1 - (j - 1))*(f2 - 1);
            }
            //cout << "Fr = " << f1 << " Fc = " << f2 << " = ";
            no_of_subrectangles += row_contribution*column_contribution;
            //cout << no_of_subrectangles << " = " << row_contribution << "x" << column_contribution << "\n";
            
            if(f1 == f2)
            {
                continue;
            }
            
            column_contribution = 0;
            
            if(f1 <= column_segments.back())
            {
                int j = upper_bound(all(column_segments), f1 - 1) - column_segments.begin();
                
                column_contribution = (column_sum.back() - column_sum[j - 1]) -
                    (column_segments.size() - 1 - (j - 1))*(f1 - 1);
            }
            
            row_contribution = 0;
            //cout << "F2 = " << f2 << " Back = " << row_segments.back() << "\n";
            
            if(f2 <= row_segments.back())
            {
                int j = upper_bound(all(row_segments), f2 - 1) - row_segments.begin();
                
                row_contribution = (row_sum.back() - row_sum[j - 1]) -
                    (row_segments.size() - 1 - (j - 1))*(f2 - 1);
                
                //cout << "Sum = " << (row_sum.back() - row_sum[j - 1]) << " - "
                 //<< (row_segments.size() - 1 - (j - 1))*(f2 - 1) << "\n";
            }
            
            //cout << "Fr = " << f2 << " Fc = " << f1 << " = ";
            no_of_subrectangles += row_contribution*column_contribution;
            //cout << no_of_subrectangles << " = " << row_contribution << "x" << column_contribution << "\n";
        }
    }
    
    cout << no_of_subrectangles << "\n";
    return 0;
}
