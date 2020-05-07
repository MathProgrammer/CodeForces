//
//  main.cpp
//  Remove One Element
//
//  Created by Saikat Ghosh on 13/12/19.
//  Copyright © 2019 Saikat Ghosh. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int no_of_elements;
    cin >> no_of_elements;
    
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];
    }
    
    const int WITHOUT_DELETE = 0, WITH_DELETE = 1;
    vector <vector <int> > max_length_till(no_of_elements + 1, vector <int> (2, 0));
    
    max_length_till[1][WITHOUT_DELETE] = 1;
    max_length_till[1][WITH_DELETE] = 1;
    
    for(int i = 2; i <= no_of_elements; i++)
    {
        max_length_till[i][WITH_DELETE] = 1;
        max_length_till[i][WITHOUT_DELETE] = 1;
        
        if(i >= 1 && A[i] > A[i - 1])
        {
            max_length_till[i][WITHOUT_DELETE] =                               max_length_till[i - 1][WITHOUT_DELETE] + 1;
            
            max_length_till[i][WITH_DELETE] = 1 + max_length_till[i - 1][WITH_DELETE];
        }
        
        if(i >= 2 && A[i] > A[i - 2])
        {
            max_length_till[i][WITH_DELETE] = max(max_length_till[i][WITH_DELETE],
             1 + max_length_till[i - 2][WITHOUT_DELETE]);
        }
    }
    
    int answer = 0;
    for(int i = 1; i <= no_of_elements; i++)
    {
        int answer_here = max(max_length_till[i][WITHOUT_DELETE], max_length_till[i][WITH_DELETE]);
        answer = max(answer, answer_here);
    }
    
    cout << answer << "\n";
    return 0;
}
