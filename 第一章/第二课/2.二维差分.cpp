
#include <iostream>
using namespace std;

const int N = 1010;

int n,m,q;
int a[N][N],b[N][N];


// 插入操作和构造差分矩阵的操作是一样的
void insert(int x1,int y1,int x2,int y2,int c)
{
    b[x1][y1] += c;
    b[x1][y2+1] -= c;
    b[x2+1][y1] -= c;
    b[x2+1][y2+1] += c;
}

int main()
{
    // 输入矩阵的长和宽，以及操作的次数
    scanf("%d%d%d",&n,&m,&q);

    // 读入a矩阵
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    // 构造残差
    for (int i = 1;i<=n;i ++ )
    {
        for (int j = 1;j <=m;j++)
        {
            insert(i,j,i,j,a[i][j]);
        }
    }

    // 操作加入c
    while(q--)
    {
        int x1,y1,x2,y2,c;
        cin >> x1 >>y1>>x2>>y2>>c;
        insert(x1,y1,x2,y2,c);
    }

    // 计算前缀和
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1;j<=m;j++)
        {
            b[i][j] += b[i-1][j] + b[i][j-1] -b[i-1][j-1];
        }
    }

    //输出新矩阵
    for (int i = 1; i<=n;i++)
    {
        for (int j = 1;j<=m;j++) 
        {
            printf("%d ",b[i][j]);
        }
        puts(""); // 换行
    }
    return 0;
}