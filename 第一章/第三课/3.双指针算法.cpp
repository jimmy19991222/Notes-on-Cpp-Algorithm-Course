// 归并排序： 指向两个序列
// 快速排序： 指向一个序列

// 双指针算法核心的思想： 
// for (int i = 0;i<n;i++)
//      for (int j = 0;j<n;j++)
// O(n^2)

// 将上面的朴素算法优化到O(n)

/*
for (i = 0;j = 0;i<n;i++)
{
    while(j<i && check(i,j)) j++;
    // 道题目的具体逻辑
}
*/

// 题目1: 输入一串字符串，将空格隔开的单词输出，每个单词占一行
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    char str[1000];
    gets(str);
    int n = strlen(str);
    for (int i = 0; i < n;i++)
    {
        int j = i;
        while(j<n && str[j] != ' ') j++;

        // 这道题的具体逻辑
        for (int k = i; k < j; k++) cout << str[k];
        cout << endl;

        i = j;
    }
    return 0;
}


// 题目2: 最长持续不重复子序列
// 输入 5  \n 1 2 2 3 5  输出 3

#include <iostream>
using namespace std;

const int N = 1e6;

int a[N],s[N];
int n;

int main()
{
    cin >> n;
    for (int i = 0;i < n; i++) cin >> a[i];
    int res = 0;
    for (int i = 0,j = 0; i < n; i++)
    {
        s[a[i]]++;
        while(j<=i && s[a[i]] > 1)
        {
            s[a[j]] --;
            j ++;
        }
        res = max(res, i-j+1);
    }
    cout << res << endl;
    return 0;
}
