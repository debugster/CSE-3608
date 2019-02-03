#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define PI acos(-1.0)
#define EPS 1e-4

int main()
{
    freopen("2-4-in.txt", "r", stdin);
    //freopen("2-4-out.txt", "w", stdout);

    int n, i, j;
    double x, y, ans, numerator, denominator;
    vector<double>allX;
    vector<double>allY;

    while (true) {
        cout << "Number of points in the table: ";
        cin >> n;

        if (!n) {
            break;
        }

        allX.assign(n, 0);
        allY.assign(n, 0);
        for (i = 0; i < n; i++) {
            cout << "Enter x" << i << " y" << i << "\n";
            cin >> allX[i] >> allY[i];
        }

        cout << "Value for x: ";
        cin >> x;

        ans = 0.0;
        for (i = 0; i < n; i++) {
            numerator = denominator = 1.0;
            for (j = 0; j < n; j++) {
                if (j == i) {
                    continue;
                }

                numerator *= (x - allX[j]);
                denominator *= (allX[i] - allX[j]);
            }

            ans += (numerator * allY[i]) / denominator;
        }

        cout << "f(" << x << ") = " << ans << "\n";
    }

    return 0;
}




