// 差分是前缀和的逆运算
// 前缀和a，差分b
// 让[l,r]的a都加上c，bl+c,br+1-c

// 只需要O（1）

#include <iostream>
using namespace std;

const int N = 100010;

int n, m;
int a[N], b[N];

void insert(int l, int r, int c)
{
    b[l] += c;
    b[r + 1] -= c;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    //构造差分数列的方法也是insert函数
    for (int i = 1; i <= n; i++)
        insert(i, i, a[i]);

    while (m--)
    {
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        insert(l, r, c);
    }

    for (int i = 1; i <= n; i++)
        b[i] += b[i - 1];
    for (int i = 1; i <= n; i++)
        printf("%d", b[i]);

    return 0;
}