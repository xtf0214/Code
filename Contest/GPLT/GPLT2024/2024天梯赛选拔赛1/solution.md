[TOC]



# L1-1 2018我们要赢

```python
print("""2018
wo3 men2 yao4 ying2 !""")
```

# L1-2 心理阴影面积

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    int x, y;
    cin >> x >> y;
    cout << (100 * 100 / 2 - x * y / 2 - (100 - x) * y - (100 - x) * (100 - y) / 2) << '\n';
}
```

# L1-3 判断素数

```cpp
#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long x) {
    for (long long i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return x > 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long x;
        cin >> x;
        cout << (isPrime(x) ? "Yes" : "No") << '\n';
    }
}
```

# L1-4 调和平均

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    double x = 0;
    for (int i = 0; i < n; i++) {
        double a;
        cin >> a;
        x += 1.0 / a;
    }
    printf("%.2lf\n", 1.0 / (x / n));
}
```

# L1-5 情人节

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<string> v;
    string s;
    while (cin >> s, s != ".") {
        v.push_back(s);
    }
    if (v.size() >= 14) {
        cout << v[1] << " and " << v[13] << " are inviting you to dinner...\n";
    } else if (v.size() >= 2) {
        cout << v[1] << " is the only one for you...\n";
    } else {
        cout << "Momo... No one is for you ...\n";
    }
}
```

# L1-6 复制粘贴

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    while (n--) {
        int l, r;
        cin >> l >> r;
        string ls, rs;
        cin >> ls >> rs;
        string cx = s.substr(l - 1, r - l + 1);
        s.erase(s.begin() + l - 1, s.begin() + r - 1 + 1);
        auto pos = s.find(ls + rs);
        if (pos == -1) {
            s += cx;
        } else {
            s.insert(pos + ls.size(), cx);
        }
    }
    cout << s << '\n';
}
```

# L1-7 古风排版

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.get();
    string s;
    getline(cin, s);
    while (s.size() % n != 0)
        s.push_back(' ');
    vector<string> ss(n);
    for (int i = 0; i < s.size(); i++)
        ss[i % n] += s[i];
    for (int i = 0; i < n; i++) {
        reverse(ss[i].begin(), ss[i].end()); // 逆转所有元素的位置
        cout << ss[i] << '\n';
    }
}
```

# L1-8 分寝室

```cpp
#include <bits/stdc++.h>
using namespace std;

// 分解n的所有因数(不包括1)
vector<int> get(int n) {
    set<int> s;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            s.insert(i), s.insert(n / i);
    s.insert(n);
    return vector<int>(s.begin(), s.end());
}
int main() {
    int n, n1, n0;
    cin >> n0 >> n1 >> n;
    vector<int> a1 = get(n1), a0 = get(n0); // a1:每个男寝可分配的人数，a0:每个女寝可分配的人数
    int mn = 1e9;
    pair<int, int> ans = {0, 0};
    for (int x : a0) {
        for (int y : a1) {
            if (n0 / x + n1 / y == n) { // n0/x女寝宿舍数 n1/y男寝宿舍数
                if (mn > abs(x - y)) {
                    mn = abs(x - y);
                    ans = {n0 / x, n1 / y};
                }
            }
        }
    }
    if (ans == pair<int, int>{0, 0}) {
        cout << "No Solution";
    } else {
        cout << ans.first << ' ' << ans.second;
    }
}
```

# L2-1 插松枝

```flow
st1=>start: start
st2=>start: start
st3=>start: start
st4=>start: start
st5=>start: start
st6=>start: start
ed1=>end: end
ed2=>end: end
ed3=>end: end
ed4=>end: end
cond1=>condition: tree.size()<k
    cond2=>condition: !tree.empty()
        cond3=>condition: !box.empty()
            op1=>operation: tree.push_back(box.top());box.pop()        
        cond4=>condition: !a.empty()
            op2=>operation: tree.push_back(a.back());a.pop_back();
        cond5=>condition: !box.empty() && box.top()<=tree.back()
            op3=>operation: tree.push_back(box.top());box.pop()
        cond6=>condition: !a.empty()
            cond7=>condition: a.back()<=tree.back()
                op4=>operation: tree.push_back(a.top());a.pop()
            cond8=>condition: box.size()><m
                op5=>operation: box.push(a.back());a.pop_back();

st1->cond1
cond1(yes)->cond2
    cond2(yes)->cond3
        cond3(yes)->op1->st2
        cond3(no)->cond4
            cond4(yes)->op2->st3
            cond4(no)->ed1
    cond2(no)->cond5
        cond5(yes)->op3->st6
        cond5(no)->cond6
            cond6(yes)->cond7
                cond7(yes)->op4->st4
                cond7(no)->cond8
                    cond8(yes)->op5->st5
                    cond8(no)->ed2
            cond6(no)->ed3
cond1(no)->ed4
```



```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    reverse(a.begin(), a.end());
    stack<int> box;
    while (!a.empty() || !box.empty()) { // 盒子和推送器都不为空时，继续做松枝
        vector<int> tree;
        while (tree.size() < k) {
            if (tree.empty()) {     // 松枝干为空
                if (!box.empty()) { // 从盒子里取
                    tree.push_back(box.top());
                    box.pop();
                } else {           // 从推送器取
                    if (a.empty()) // 小盒子中最上面的松针不满足要求，但推送器上已经没有松针了
                        break;
                    tree.push_back(a.back());
                    a.pop_back();
                }
            } else {                                            // 松枝干非空
                if (!box.empty() && box.top() <= tree.back()) { // 从盒子里取
                    tree.push_back(box.top());
                    box.pop();
                } else {           // 从推送器取
                    if (a.empty()) // 小盒子中最上面的松针不满足要求，但推送器上已经没有松针了
                        break;
                    int x = a.back();
                    if (x <= tree.back()) { // 推送器满足要求
                        tree.push_back(x);
                    } else {                   // 推送器不满足要求
                        if (box.size() >= m) { // 小盒子已经满了，但推送器上取到的松针仍然不满足要求。
                            break;
                        } else { // 如果推送器上拿到的仍然不满足要求，就把拿到的这片堆放到小盒子里，继续去推送器上取下一片。
                            box.push(x);
                        }
                    }
                    a.pop_back();
                }
            }
        }
        // 手中的松枝干上已经插满了松针，将之放到成品篮里，开始下一根松枝的制作。
        for (int i = 0; i < tree.size(); i++)
            cout << tree[i] << " \n"[i == tree.size() - 1];
    }
}
```

# L2-2 列车调度

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    vector<int> t{a[0]};
    for (int i = 1; i < n; i++) {
        auto pos = lower_bound(t.begin(), t.end(), a[i]);
        if (pos == t.end()) {
            t.push_back(a[i]);
        } else {
            *pos = a[i];
        }
    }
    cout << t.size();
}
```

# L2-3 愿天下有情人都是失散多年的兄妹

```cpp
#include <bits/stdc++.h>
using namespace std;

struct P {
    char sex;
    int f = -1, m = -1;
} p[100010];
map<int, int> mp;
bool flag;
void dfs(int u, int dep) {
    if (dep > 5 || u == -1)
        return;
    mp[u]++;
    if (mp[u] >= 2)
        flag = 0;
    dfs(p[u].f, dep + 1);
    dfs(p[u].m, dep + 1);
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cin >> p[x].sex >> p[x].f >> p[x].m;
        if (p[x].f != -1)
            p[p[x].f].sex = 'M';
        if (p[x].m != -1)
            p[p[x].m].sex = 'F';
    }
    int m;
    cin >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        if (p[x].sex == p[y].sex) {
            cout << "Never Mind\n";
        } else {
            flag = 1;
            mp.clear();
            dfs(x, 1);
            dfs(y, 1);
            if (flag)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
}
```

# L2-4 网红点打卡攻略

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n + 1, vector<int>(n + 1, 0));
    for (int _ = 0; _ < m; _++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u][v] = G[v][u] = w;
    }
    int T;
    cin >> T;
    int cnt = 0;
    pair<int, int> ans = {0, 1e9};
    for (int id = 1; id <= T; id++) {
        int k;
        cin >> k;
        vector<int> a;
        set<int> s;
        a.push_back(0);
        for (int i = 0; i < k; i++) {
            int x;
            cin >> x;
            a.push_back(x);
            s.insert(x);
        }
        a.push_back(0);
        int sum = 0;
        bool ok = true;
        for (int i = 1; i < a.size(); i++) {
            if (!G[a[i - 1]][a[i]])
                ok = false;
            sum += G[a[i - 1]][a[i]];
        }
        if (ok && s.size() == n && k == n) {
            cnt++;
            if (ans.second > sum) {
                ans = {id, sum};
            }
        }
    }
    cout << cnt << '\n';
    cout << ans.first << ' ' << ans.second;
}
```

# L3-1 特殊堆栈

树状数组维护栈中每个数字的出现次数，树状数组上二分查找第k小

```cpp
#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    vector<int> tr;
    BIT(int n) : n(n), tr(n + 1, 0) {}
    void add(int i, int d) {
        for (; i <= n; i += (i & -i))
            tr[i] += d;
    }
    int get(int i) {
        int s = 0;
        for (; i; i -= (i & -i))
            s += tr[i];
        return s;
    }
    int kth(int k) {
        int l = 0, r = n + 1, mid;
        while (r - l > 1)
            (get(mid = (l + r) >> 1) < k) ? l = mid : r = mid;
        return r;
    }
};

int main() {
    int n;
    cin >> n;
    BIT bit(1e5);
    stack<int> s;
    while (n--) {
        string op;
        cin >> op;
        if (op == "Pop") {
            if (s.empty()) {
                cout << "Invalid\n";
            } else {
                bit.add(s.top(), -1);
                cout << s.top() << '\n';
                s.pop();
            }
        } else if (op == "Push") {
            int x;
            cin >> x;
            bit.add(x, 1);
            s.push(x);
        } else {
            if (s.empty()) {
                cout << "Invalid\n";
            } else {
                int k = (s.size() + 1) / 2;
                int val = bit.kth(k);
                cout << val << '\n';
            }
        }
    }
}
```

vector实现简易平衡树

```cpp
#include <bits/stdc++.h>
using namespace std;

template <typename T> struct BST {
    vector<T> tr;
    void insert(T x) { tr.insert(lower_bound(tr.begin(), tr.end(), x), x); }
    void erase(T x) { tr.erase(lower_bound(tr.begin(), tr.end(), x)); }
    int rank(T x) { return lower_bound(tr.begin(), tr.end(), x) - tr.begin() + 1; }
    int kth(int x) { return tr.at(x - 1); }
    int pre(int x) { return *prev(lower_bound(tr.begin(), tr.end(), x)); }
    int nxt(int x) { return *upper_bound(tr.begin(), tr.end(), x); }
};

int main() {
    int n;
    cin >> n;
    BST<int> bst;
    stack<int> s;
    while (n--) {
        string op;
        cin >> op;
        if (op == "Pop") {
            if (s.empty()) {
                cout << "Invalid\n";
            } else {
                bst.erase(s.top());
                cout << s.top() << '\n';
                s.pop();
            }
        } else if (op == "Push") {
            int x;
            cin >> x;
            bst.insert(x);
            s.push(x);
        } else {
            if (s.empty()) {
                cout << "Invalid\n";
            } else {
                int k = (s.size() + 1) / 2;
                int val = bst.kth(k);
                cout << val << '\n';
            }
        }
    }
}
```

