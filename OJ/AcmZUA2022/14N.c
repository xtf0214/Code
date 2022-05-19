#include <stdio.h>
int triangle_sum(int *a, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            sum += a[i * n + j];
    return sum;
}
int main()
{
    int a[3][3];
    int i, j;
    int sum;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    sum = triangle_sum(&a[0][0], 3);
    printf("%d", sum);
    return 0;
}