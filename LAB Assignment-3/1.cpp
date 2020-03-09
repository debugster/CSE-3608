//#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <bitset>
#include <string>
#include <utility>
#include <iterator>
#include <fstream>
#include <sstream>
#include <numeric>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <ctime>
#include <cassert>

using namespace std;

/* typedef starts */

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

/* typedef ends */

/* macro starts */

#define PI acos(-1.0)
#define EPS 1e-9
#define fastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define sinD(degree) sin((degree * PI) / 180.0)
#define cosD(degree) cos((degree * PI) / 180.0)
#define tanD(degree) tan((degree * PI) / 180.0)
#define cotD(degree) (1.0 / tanD(degree))
#define secD(degree) (1.0 / cosD(degree))
#define cosecD(degree) (1.0 / sinD(degree))
#define asinD(value) (asin(value) * 180.0) / PI
#define acosD(value) (acos(value) * 180.0) / PI
#define atanD(value) (atan(value) * 180.0) / PI

/* macro ends */

/* function starts */

/// calculates n-th (0-based) Gray Code
template<typename dataType>
dataType nthGrayCode(dataType n)
{
    return (n ^ (n >> 1));
}

/// generates all possible subsets for the given set
template<typename dataType>
void generateAllSubset(vector<dataType> &data)
{
    int i, j, n;
    n = data.size();

    for (i = 0; i < (1 << n); i++) {
        for (j = 0; j < n; j++) {
            if (i & (1 << j)) {
                cout << data[j] << " ";
            }
        }
        cout << "\n";
    }
}

/* function ends */

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    fastIO;

    double allX[] = {1, 2, 3, 4, 5};
    double allY[] = {1, 8, 27, 64, 125};
    int tableSize = sizeof allY / sizeof allY[0];
    vector<double>delY[tableSize];
    double x = 1;
    double h = allX[1] - allX[0];
    double u = (x - allX[0]) / h;

    for (int i = 0; i < tableSize; i++) {
        delY[0].push_back(allY[i]);
    }

    for (int i = 1; i < tableSize; i++) {
        for (int j = 1; j < delY[i - 1].size(); j++) {
            delY[i].push_back(delY[i - 1][j] - delY[i - 1][j - 1]);
        }
    }

    double firstD = delY[1][0] + (2 * u - 1) * (delY[2][0] / 2) + (3 * u * u - 6 * u + 2) * (delY[3][0] / 6) + (4 * u * u * u - 18 * u * u + 22 * u - 6) * (delY[4][0] / 24);
    firstD /= h;

    double secondD = delY[2][0] + (6 * u - 6) * (delY[3][0] / 6) + (12 * u * u - 36 * u + 22) * (delY[4][0] / 24);
    secondD /= (h * h);

    cout << "First Derivative = " << setprecision(3) << fixed << firstD << "\n";
    cout << "Second Derivative = " << setprecision(3) << fixed << secondD << "\n";

    return 0;
}


