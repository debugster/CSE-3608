#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define PI acos(-1.0)
#define EPS 1e-9

int main()
{
    freopen("1-1-in.txt", "r", stdin);
    freopen("1-1-out.txt", "w", stdout);

    string number, temp;
    int i, _count;
    bool decimalPoint;

    while (true) {
        cout << "Enter a number: ";
        cin >> number;

        if (!number.size()) {
            break;
        }

        temp = number;

        // removing all preceding 0s
        while (temp[0] == '0') {
            temp.erase(0, 1);
        }

        // looking for decimal point
        decimalPoint = false;
        for (i = 0; i < temp.size(); i++) {
            if (temp[i] == '.') {
                decimalPoint = true;
                break;
            }
        }

        if (!decimalPoint) {
            // if decimal point is not found,
            // remove all trailing 0s
            i = temp.size() - 1;
            while (temp[i] == '0') {
                temp.erase(i, 1);
                i--;
            }
            _count = temp.size();
        }
        else {
            if (temp[0] == '.') {
                // if there are no non-zero digits to the left of the decimal point,
                // then remove all 0s between decimal point and the next non-zero digit
                while (temp[1] == '0') {
                    temp.erase(1, 1);
                }
            }

            _count = temp.size() - 1; // decimal point is not a digit
        }

        cout << number << " has " << _count << " significant digits.\n";
        number = "";
    }

    return 0;
}
