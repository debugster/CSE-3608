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

int temp[4][4];

int det3x3()
{
    int ans = 0;
    ans += temp[1][1] * (temp[2][2] * temp[3][3] - temp[2][3] * temp[3][2]);
    ans -= temp[1][2] * (temp[2][1] * temp[3][3] - temp[2][3] * temp[3][1]);
    ans += temp[1][3] * (temp[2][1] * temp[3][2] - temp[2][2] * temp[3][1]);
    return ans;
}

int main()
{
    freopen("6-in.txt", "r", stdin);
    //freopen("6-out.txt", "w", stdout);

    fastIO;

    int n = 4;
    int matrix[n + 1][n + 1];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> matrix[i][j];
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            int m = 1;
            for (int k = 1; k <= n; k++) {
                if (k == i) {
                    continue;
                }
                temp[j - 1][m] = matrix[j][k];
                m++;
            }
        }

        cout << det3x3() << "\n";

        int d = matrix[1][i] * det3x3();
        if (i % 2 == 1) {
            ans += d;
        }
        else {
            ans -= d;
        }
    }

    cout << "Determinant = " << ans << "\n";

    return 0;
}


