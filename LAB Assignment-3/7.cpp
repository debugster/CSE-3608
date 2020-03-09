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

const int n = 3;

double A[n + 1][n + 1] = {
                {0, 0, 0, 0},
                {0, 1, 1, 1},
                {0, 1, 2, 3},
                {0, 1, 3, 4}
                };

double B[n + 1] = {0, 1, 6, 6};

double det3x3()
{
    double ans = 0;
    ans += A[1][1] * (A[2][2] * A[3][3] - A[2][3] * A[3][2]);
    ans -= A[1][2] * (A[2][1] * A[3][3] - A[2][3] * A[3][1]);
    ans += A[1][3] * (A[2][1] * A[3][2] - A[2][2] * A[3][1]);
    return ans;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    fastIO;

    double detA = det3x3();
    double cofactor[n + 1][n + 1];

    vector<double>data;

    data.clear();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int row = 1; row <= n; row++) {
                for (int col = 1; col <= n; col++) {
                    if (row == i || col == j) {
                        continue;
                    }
                    data.push_back(A[row][col]);
                }
            }

            cofactor[i][j] = (data[0] * data[3]) - (data[1] * data[2]);
            if ((i + j) % 2 == 1) {
                cofactor[i][j] *= -1;
            }

            data.clear();
        }
    }

    double adjA[n + 1][n + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            adjA[i][j] = cofactor[j][i];
            adjA[i][j] /= detA;
        }
    }

    double solution[n + 1];
    for (int i = 1; i <= n; i++) {
        double x = 0;
        for (int j = 1; j <= n; j++) {
            x += adjA[i][j] * B[j];
        }
        solution[i] = x;
    }

    cout << "x = " << setprecision(3) << fixed << solution[1] << "\n";
    cout << "y = " << setprecision(3) << fixed << solution[2] << "\n";
    cout << "z = " << setprecision(3) << fixed << solution[3] << "\n";

    return 0;
}


