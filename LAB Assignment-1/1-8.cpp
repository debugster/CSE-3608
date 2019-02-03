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

double fX(double x)
{
    double ans = 0;
    for (int i = degree; i >= 0; i--) {
        ans += allA[i] * pow(x, i);
    }
    return ans;
}

int main()
{
    freopen("1-8-in.txt", "r", stdin);
    freopen("1-8-out.txt", "w", stdout);

    int i;
    double x, x1, x2;

    while (true) {
        cout << "Degree of polynomial equation: ";
        cin >> degree;

        if (!degree) {
            break;
        }

        cout << "Enter the co-efficients: ";
        for (i = degree; i >= 0; i--) {
            cin >> allA[i];
        }

        cout << "Initial guess for x1: ";
        cin >> x1;
        cout << "Initial guess for x2: ";
        cin >> x2;

        while (true) {
            x = x2 - (fX(x2) * (x2 - x1)) / (fX(x2) - fX(x1));

            if (fabs(x - x2) > EPS) {
                x1 = x2;
                x2 = x;
            }
            else {
                break;
            }
        }

        cout << "root = " << setprecision(3) << fixed << x << "\n";
    }

    return 0;
}



