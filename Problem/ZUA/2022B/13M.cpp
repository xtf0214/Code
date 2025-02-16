// 1029 Problem  M	求最大公约数（第三讲）
#include <bits/stdc++.h>
using namespace std;

int gcd(int m, int n) { return n ? gcd(n, m % n) : m; }
void solve()
{
    int n, m;
    cin >> m >> n;
    cout << gcd(m, n) << endl;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}