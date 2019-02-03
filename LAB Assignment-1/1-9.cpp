#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define PI acos(-1.0)
#define EPS 1e-4
#define MAX 100

int allP[MAX];
int allQ[MAX];

int main()
{
    freopen("1-9-in.txt", "r", stdin);
    freopen("1-9-out.txt", "w", stdout);

    int degree, i, x;

    while (true) {
        cout << "Degree of polynomial: ";
        cin >> degree;

        if (!degree) {
            break;
        }

        cout << "Co-efficients: ";
        for (i = degree; i >= 0; i--) {
            cin >> allP[i];
        }

        cout << "Root, x: ";
        cin >> x;

        allQ[degree] = 0;
        for (i = degree - 1; i >= 0; i--) {
            allQ[i] = allP[i + 1] + x * allQ[i + 1];
        }

        cout << "Co-efficients of q(x): ";
        for (i = degree - 1; i >= 0; i--) {
            cout << allQ[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}


