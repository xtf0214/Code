/**
 * @file    :   主席树（传引用update）
 * @author  :   Tanphoon
 * @date    :   2023/12/13 15:51
 * @version :   2023/12/13 15:51
 * @link    :   https://www.cnblogs.com/RabbitHu/p/segtree.html
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int cnt, rt[N];
struct Node {
    int l, r, sum;
} tr[N << 5];

int kth(int k, int p, int q, int l, int r) {
    if (l == r)
        return l;
    int mid = (l + r) / 2;
    int x = tr[tr[q].l].sum - tr[tr[p].l].sum;
    if (x >= k)
        return kth(k, tr[p].l, tr[q].l, l, mid);
    else
        return kth(k - x, tr[p].r, tr[q].r, mid + 1, r);
}
void update(int k, int d, int p, int &q, int l, int r) {
    q = ++cnt;
    tr[q] = tr[p];
    if (l == r) {
        tr[q].sum += d;
        return;
    }
    int mid = (l + r) / 2;
    if (k <= mid)
        update(k, d, tr[p].l, tr[q].l, l, mid);
    else
        update(k, d, tr[p].r, tr[q].r, mid + 1, r);
    tr[q].sum = tr[tr[q].l].sum + tr[tr[q].r].sum;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), d;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        d.push_back(a[i]);
    }
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());
    int nn = d.size();
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(d.begin(), d.end(), a[i]) - d.begin() + 1;
        update(a[i], 1, rt[i], rt[i + 1], 1, nn);
    }
    while (m--) {
        int l, r, k;
        cin >> l >> r >> k;
        int idx = kth(k, rt[l - 1], rt[r], 1, nn);
        cout << d[idx - 1] << '\n';
    }
}