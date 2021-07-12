
// 1. 求n的第k位数字 n >> k & 1

// 2. lowbit(x) 返回x的最后一位1
// x = 1010 lowbit(x)=10

// x & -x = x & (~x + 1)


// 问题： 求一个数的二进制表示中有多少1
#include <iostream>
using namespace std;

int lowbit(int x)
{
    return x & -x;
}

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int x;
        cin >> x;

        int res = 0;
        while(x) x -= lowbit(x), res++; //每次减去最后一位1
        cout << res << endl;
    }
    return 0;
}

