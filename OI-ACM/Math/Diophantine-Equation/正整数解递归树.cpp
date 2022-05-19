#include <iostream>
using namespace std;
int x[101];
int cnt[1001]; //
void dfs(int k, int m, int n)
{
    cnt[k]++;          //每个层调用次数
    bool first = true; //是否第一次调用决定缩减
    if (k == 1)
    {
        x[k] = n;
        printf("%d_%d_%d", k, n, cnt[k]); //打印信息
        cout << endl;
        return;
    }
    for (int i = 1; i <= n - k + 1; i++)
    {
        x[k] = i;
        if (!first) //若非第一次调用,缩进
            for (int i = m; i > k; i--)
                cout << "           ";
        printf("%d_%d_%d---|%d|", k, n, cnt[k], i); //打印信息
        dfs(k - 1, m, n - i);
        first = false;
    }
    cout << endl;
}
int main()
{
    dfs(5, 5, 9);
    return 0;
}