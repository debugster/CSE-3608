#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define PI acos(-1.0)
#define EPS 1e-4

int main()
{
    freopen("2-5-in.txt", "r", stdin);
    freopen("2-5-out.txt", "w", stdout);

    int n, i, j, k;
    double x, y, ans, temp;
    vector<vector<double> >allX, allY;

    while (true) {
        cout << "Number of points in the table: ";
        cin >> n;

        if (!n) {
            break;
        }

        allX.assign(n, vector<double>());
        allY.assign(n, vector<double>());
        for (i = 0; i < n; i++) {
            cout << "Enter x" << i << " y" << i << "\n";
            cin >> x >> y;
            allX[0].push_back(x);
            allY[0].push_back(y);
        }

        // denominator table
        for (i = 1; i < n; i++) {
            for (j = 0, k = j + i; j < n && k < n; j++, k++) {
                x = allX[0][k] - allX[0][j];
                allX[i].push_back(x);
            }
        }

        for (i = 1; i < n; i++) {
            for (j = 1; j < allY[i - 1].size(); j++) {
                y = (allY[i - 1][j] - allY[i - 1][j - 1]) / (allX[i][j - 1]);
                allY[i].push_back(y);
            }
        }

        cout << "Enter value for x: ";
        cin >> x;

        ans = allY[0][0];
        for (i = 1; i < n; i++) {
            temp = 1.0;
            for (j = 0; j < i; j++) {
                temp *= (x - allX[0][j]);
            }
            ans += (temp * allY[i][0]);
        }

        cout << "f(" << x << ") = " << ans << "\n";
    }

    return 0;
}

