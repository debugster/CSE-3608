#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define PI acos(-1.0)
#define EPS 1e-4

int main()
{
    freopen("2-1-in.txt", "r", stdin);
    freopen("2-1-out.txt", "w", stdout);

    int n, i, j;
    double x, y;
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

        for (i = 1; i < n; i++) {
            for (j = 1; j < allY[i - 1].size(); j++) {
                y = allY[i - 1][j] - allY[i - 1][j - 1];
                allY[i].push_back(y);
            }
        }

        for (i = 1; i < n; i++) {
            cout << "del^" << i << "y:";
            for (j = 0; j < allY[i].size(); j++) {
                cout << " " << allY[i][j];
            }
            cout << "\n";
        }
    }

    return 0;
}

