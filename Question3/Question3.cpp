#include <bits/stdc++.h>
using namespace std;

int portfolio_profit_maximisation(int maxSum, vector<int> a, vector<int> b) {
    //write your code here
    int n = a.size();
    int m = b.size();

    int count = 0, ans = 0;
    int i = 0, j = 0;
    while (i < n && j < m) {
        int val = min(a[i], b[j]);
        if (count + val > maxSum)break;
        if (a[i] > b[j]) {
            count += b[j++];
        }
        else {
            count += a[i++];
        }
        ans++;
    }

    while (i < n) {
        if (count + a[i] > maxSum)break;
        count += a[i++];
        ans++;
    }

    while (j < m) {
        if (count + b[j] > maxSum)break;
        count += b[j++];
        ans++;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int n, m, x;
    cin >> n >> m >> x;

    vector<int> a(n);
    vector<int> b(m);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    int result = portfolio_profit_maximisation(x, a, b);
    cout << result;
    return 0;
}