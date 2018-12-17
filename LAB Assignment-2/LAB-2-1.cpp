#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int n, i, j, x, y;
    vector<int>allX, allY;
    vector<vector<int> >delY;

    //cout << "Value of n: ";
    cin >> n;

    delY.assign(n + 1, vector<int>());
    for (i = 0; i <= n; i++) {
        //cout << "x[" << i << "] = ";
        cin >> x;
        allX.push_back(x);
        //cout << "y[" << i << "] = ";
        cin >> y;

        allY.push_back(y);
        delY[0].push_back(y);
    }
    //delY.push_back(allY);

    for (i = 1; i <= n; i++) {
        for (j = 1; j < delY[i - 1].size(); j++) {
            //cout << delY[i - 1][j] << " " << delY[i - 1][j - 1] << "\n";
            delY[i].push_back(delY[i - 1][j] - delY[i - 1][j - 1]);
        }
    }

    for (i = 1; i < delY.size(); i++) {
        cout << "del " << i << ":";
        for (j = 0; j < delY[i].size(); j++) {
            cout << " " << delY[i][j];
        }
        cout << "\n";
    }

    return 0;
}
