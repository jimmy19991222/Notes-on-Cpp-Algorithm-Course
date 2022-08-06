## Trie

Trie 树 用于快速存储和查找字符串集合的数据结构

字典形式

 高效查找某个单词是否在集合中出现

```c++
#include <iostream>
using namespace std;

const int N = 1e5+10;
int son[N][26], cnt[N], idx; // 下标是0的电，既是跟节点， 又是空节点; son[N][26]相当于链表里的ne[N]

void insert(char str[])
{
  int p = 0;
  for (int i = 0; str[i]; i++)
  {
    int u = str[i] - 'a';
    if (!son[p][u]) son[p][u] = ++idx;
    p = son[p][u];
	}
  cnt[p] ++;
}

int query(char str[])
{
 	int p = 0;
  for(int i = 0; str[i]; i++)
  {
    int u = str[i] - 'a';
    if (!son[p][u]) return 0;
    p = son[p][u];
  }
  return cnt[p];
}


```



## 最大异或对

```c++
#include<iostream>
#include<algorithm>
using namespace std;
int const N = 1e5+10, M = 31*N;

int n;
int a[N];
int son[M][2], idx;

void insert(int x)
{
  int p=0; // 根节点
  for (int i = 30; i>=0; i--)
  {
    int u = x >> i & 1; // 取 x 的第 i 位的二进制数
    if (!son[p][u]) son[p][u] = ++idx;
    p = son[p][u];
	}
}

int search(int x)
{
  int p = 0; int res = 0;
  for (int i = 30; i>=0; i--) // 从最大位开始找
  {
    int u = x >> i & 1;
    if (son[p][!u]) // 如果当前层有对应的不相同的数
    {
      p = son[p][!u]; // p指向不同数的地址
      res = res * 2 + 1; // *2 相当于左移一位，然后如果找到对应位置有不同的数，就将结果变为 11...1
    }
    else
    {
      p = son[p][u]; // 当前层都相同，那就只能往下继续找
      res = res * 2; // 找下一层，就把上一层的值左移一位
    }
  }
  return res;
}

int main()
{
  cin >> n;
  idx = 0;
  for (int i = 0; i<n; i++)
  {
    cin >> a[i];
    insert(a[i]);
  }
  
  int res = 0;
  for (int i = 0; i<n; i++)
  {
    res = max(res, search(a[i]));
  }
}
```

