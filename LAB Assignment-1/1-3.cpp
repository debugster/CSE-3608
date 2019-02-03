#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define PI acos(-1.0)
#define EPS 1e-9
#define MAX 100

int allA[MAX];
int allP[MAX];

int main()
{
    freopen("3-in.txt", "r", stdin);
    freopen("3-out.txt", "w", stdout);

    int n, i, x, a;

    while (true) {
        cout << "Degree of polynomial: ";
        cin >> n;

        if (!n) {
            break;
        }

        cout << "Enter the co-efficients: ";
        for (i = n; i >= 0; i--) {
            cin >> allA[i];
        }

        cout << "Enter value for x: ";
        cin >> x;

        allP[n] = allA[n];
        for (i = n - 1; i >= 0; i--) {
            allP[i] = allP[i + 1] * x + allA[i];
        }

        cout << "f(" << x << ") = " << allP[0] << "\n";
    }

    return 0;
}


