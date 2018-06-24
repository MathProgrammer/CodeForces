#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cstdio>
#include <algorithm>
#include <map>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int A, B, C, total_students;
    cin >> A >> B >> C >> total_students;

    int passed = (A + B - C);
    int failed = total_students - passed;

    cout << (failed < 1 || C > min(A, B) ? -1 : failed);

    return 0;
}

