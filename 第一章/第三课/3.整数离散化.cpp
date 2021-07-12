
// 整数保序的离散化
// 值域跨度很大，但是很稀疏
// 有序数组：1 2 5 8 ... 10^9 映射到 连续的数组中
// a[]: 1,3,100,2000,50000
// 映射  0 1  2    3    4

// 问题：
// 1. a中可能有连续元素： 去重
// 2. 如何算出 a[i] 离散化后的值： 二分

// 去重的操作
vector<int> alls; // 存储所有待离散化的值
sort(alls.begin(),alls.end()); //将所有值排序
alls.erase(unique(alls.begin(),alls.end()),alls.end()); // 去掉重复元素

// 二分法求出x对应的离散化的值
int find(int x) // 找到第一个大于等于x的位置
{
    int l = 0, r = alls.size() - 1;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r+1; // 映射到1，2，...,n
}

// 问题：区间和
// 无限长的数轴，都是0，添加值，询问区域内的加和

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 3000100;

int n,m;
int a[N],s[N];

vector<int> alls;
vector<PII> add, query;

int find(int x)
{
    int l = 0, r = alls.size()-1;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(alls[mid] >= x) r = mid;
        else l = mid +1;
    }
    return r+1;
}

int main()
{
    cin >> n >> m;
    for(int i; i<n ;i++)
    {
        int x,c;
        cin >> x >> c;
        add.push_back({x,c});
        
        alls.push_back(x);
    }
    for (int i = 0; i < m; i ++)
    {
        int l,r;
        cin >> l >> r;
        query.push_back({l,r});

        alls.push_back(l);
        alls.push_back(r);
    }

    // 去重
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());

    for (auto item : add)
    {
        int x = find(item.first);
        a[x] += item.second;
    }

    // 预处理前缀和
    for (int i = 1; i <= alls.size();i++) s[i]=s[i-1]+a[i];

    // 处理询问
    for (auto item : query)
    {
        int l = find(item.first), r = find(item.second);
        cout << s[r] - s[r-1] << endl;
    }

    return 0;
}

// unique 函数的实现
vector<int> :: iterator unique(vector<int> &a)
{
    int j = 0;
    for (int i = 0; i< a.size(); i++)
    {
        if (!i || a[i] != a[i-1]) // 满足不是第一个或者和前一个不同，就是unique的
        {
            a[j ++ ] = a[i]; 
        }
    }// a[0] ~ a[j-1] 所有a中不重复的数
    return a.begin() + j;
}