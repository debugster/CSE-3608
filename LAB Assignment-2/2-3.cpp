#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define PI acos(-1.0)
#define EPS 1e-4

int main()
{
    freopen("2-3-in.txt", "r", stdin);
    freopen("2-3-out.txt", "w", stdout);

    int n, i, j, fact;
    double x, y, h, u, ans, tempU;
    vector<double>allX;
    vector<vector<double> >allY;

    while (true) {
        cout << "Number of points in the table: ";
        cin >> n;

        if (!n) {
            break;
        }

        allX.assign(n, 0);
        allY.assign(n, vector<double>());
        for (i = 0; i < n; i++) {
            cout << "Enter x" << i << " y" << i << "\n";
            cin >> allX[i] >> y;
            allY[0].push_back(y);
        }

        cout << "Value for x: ";
        cin >> x;

        for (i = 1; i < n; i++) {
            for (j = 1; j < allY[i - 1].size(); j++) {
                y = allY[i - 1][j] - allY[i - 1][j - 1];
                allY[i].push_back(y);
            }
        }

        h = allX[1] - allX[0];
        u = (x - allX[n - 1]) / h;

        ans = allY[0][n - 1];
        for (i = 1, fact = 1; i < n; i++) {
            tempU = u;
            for (j = 1; j < i; j++) {
                tempU *= (u + j);
            }
            fact *= i;
            ans += (tempU * allY[i][allY[i].size() - 1]) / (fact * 1.0);
        }

        cout << "f(" << x << ") = " << ans << "\n";
    }

    return 0;
}



