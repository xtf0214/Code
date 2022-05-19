#include <iostream>
#include <cstdlib>
using namespace std;
char Map[11][11];
int tx[4] = {0, 1, 0, -1}, ty[4] = {-1, 0, 1, 0};
bool OverEdge(int x, int y)
{
    if (x < 1 || x > 10 || y < 1 || y > 10)
        return true;
    else
        return false;
}
struct
{
    int x, y, v = 0;
    void Go()
    {
        if (Map[y + ty[v]][x + tx[v]] == '*' || OverEdge(x + tx[v], y + ty[v]))
            v = (v + 1) % 4, cout << "v = " << v << endl;
        else
            x += tx[v], y += ty[v], cout << x << " " << y << endl;
    }
} C, F;

int main()
{
    int time = 0;
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
        {
            cin >> Map[i][j];
            if (Map[i][j] == 'C')
                C.y = i, C.x = j;
            if (Map[i][j] == 'F')
                F.y = i, F.x = j;
        }
    cout << C.x << " " << C.y << endl
         << F.x << " " << F.y << endl;
    while (true)
    {

        cout << "C:";
        C.Go();
        cout << "F:";
        F.Go();
        time++;
        cout << "time = " << time << endl;
        if (C.x == F.x && C.y == F.y)
            break;
        if (time == 16000)
        {
            cout << 0 << endl;
            return 0;
        }
        system("pause");
    }
    cout << time << endl;
    return 0;
}