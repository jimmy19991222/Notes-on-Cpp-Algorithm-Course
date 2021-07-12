// 前缀和应用： 求解[l,r]的和 Sr-S（l-1）

#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int a[N], s[N];

int main()
{
    // ios:: sync_with_stdio(false);
    //提高cin的读取速度。副作用:不能使用scanf

    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i <= n; i++)
        s[i] = s[i - 1] + a[i];

    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d", s[r] - s[l - 1]);

    return 0;
}