// 7-2 输出2000年至n年之间的所有闰年
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 2000; i <= n; i++)
        if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))
            cout << i << endl;
    return 0;
}