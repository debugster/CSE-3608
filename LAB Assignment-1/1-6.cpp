#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define PI acos(-1.0)
#define EPS 1e-4
#define MAX 100

int degree;
int allA[MAX];
int allD[MAX]; // derivative

double fX(double x)
{
    double ans;
    for (int i = degree; i >= 0; i--) {
        ans += allA[i] * pow(x, i);
    }
    return ans;
}

double dX(double x)
{
    double ans;
    for (int i = degree - 1; i >= 0; i--) {
        ans += allD[i] * pow(x, i);
    }
    return ans;
}
int main()
{
    freopen("1-6-in.txt", "r", stdin);
    freopen("1-6-out.txt", "w", stdout);

    int i;
    double x, x0;

    while (true) {
        cout << "Degree of polynomial equation: ";
        cin >> degree;

        if (!degree) {
            break;
        }

        cout << "Co-efficients of the equation: ";
        for (i = degree; i >= 0; i--) {
            cin >> allA[i];
        }

        cout << "Co-efficients of the derivative equation: ";
        for (i = degree - 1; i >= 0; i--) {
            cin >> allD[i];
        }

        cout << "Initial guess for x: ";
        cin >> x0;

        while (true) {
            x = x0 - fX(x0) / dX(x0);

            if (fabs(x - x0) < EPS) {
                //cout << "# x  : " << x << "\n# x0  : " << x0 << "\n";
                break;
            }
            else {
                cout << "x: " << x << "\n";
                x0 = x;
            }
        }
        cout << "root: " << setprecision(3) << fixed << x << "\n";
    }

    return 0;
}

