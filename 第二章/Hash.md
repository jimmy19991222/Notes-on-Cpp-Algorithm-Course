## hash表

### hash表主要作用

离散化是一种特殊的hash方法（因为输入是单调的）

把大空间映射到小空间
$$
\{0-10^9\}\rightarrow \{0-N\}
$$
hash函数怎么写？

1. $x\ mod\ 10^5\in[0,\ 10^5)$，一般取模取的是质数，且里2的幂次最远，这样冲突最少。

   ```c++
   #include <iostream>
   using namespace std;
   
   const int N = 1e5+10;
   
   int main()
   {
     for (int i = 1e5;; i++)
     {
       bool flag = true;
       for (int j = 2; j*j <= i; j++)
       {
         if (i % j == 0)
         {
           flag = false;
           break;
         }
   		}
       if (flag)
       {
         cout << i << endl;
         break;
   		}
   	}
   }
   ```

2. 冲突（把若干不同数映射到同一个函数值）

   开放寻址法和拉链法是两种不同的处理方法 

3. 一般只有添加和查找，不会有删除操作

### hash表存储结构、写法

模拟散列表

1. 开放寻址法（更常用，找厕所法）

```c++
#include <iostream>
using namespace std;

const int N = 2e5+3, null = 0x3f3f3f3f;

int h[N];

void find(int x)
{
  int k = (x % N + N) % N;
  
  while(h[k] != null && h[k]!=x) // 如果满了就会无限循环
  {
    k ++;
    if (k == N) k = 0;
	}
  
  return k;
}

int main()
{
  int n;
  cin >> n;
  memset(h, 0x3f, sizeof h);
  
  while(n--)
  {
    char op[2];
    int x;
    
    cin >> op >> x;
    int k = find(x);
    
    if (*op == 'I') h[k] = x;
    else
    {
      if (h[k] != null) puts("Yes\n");
      else puts("No\n");
		}
  }
  return 0;
}
```

2. 拉链法

```c++
#include <cstring.h>
#include <iostream>
using namespace std;

const int N = 1e5+3;
int h[N], e[N], ne[N], idx; // h[N] 其实是一堆head，指向下一个余数相同的数

void insert(int x)
{
  int k = (x % N + N) % N; // k 就是 hash 值， 余数是一个正数
  e[idx] = x, ne[idx] = h[k], h[k] = idx++; // 单链表插入操作
}

bool find(int x)
{
  int k = (x % N + N) % N;
  for (int i = h[k]; i != -1; i = ne[i])
  {
    if (e[i] == x) return true;
	}
  return false;
}

int main()
{
  int n;
  scanf("%d", &n);
  memset(h, -1, sizeof h);
  while(n--)
  {
    char op[2];
    int x;
    scanf("%s%d", op, &x);
    if (*op == 'I') insert(x);
    else
    {
      if (find(x)) puts("Yes");
      else puts("No");
    }
	}
  return 0;
}
```



### 字符串的hash写法

字符串前缀hash法

按位hash，再按p进制相加（当 p = 131 或 13331， Q = 2^64）。

1. 不能将某一位映射成0，从1开始
2. 假定不存在冲突

好处：可以用前缀hash求出所有子段的hash



```c++
#include <iostream>
#include <cstring>

using namespace std;
typedef unsigned long long ULL;

const int N = 1e5 +10, P = 131; // P = 13331

ULL h[N], p[N]; // h[N] 表示某个前缀的hash值， p[N]表示p的多少次方，先预处理出来
int m, n;
char str[N];

ULL get(int l, int r)
{
  return h[r] - h[l-1] * p[r - l +1];
}

int main()
{
  scanf("%d%d%s", &n, &m, str + 1);
  
  p[0] = 1;
  for (int i = 1; i <= n; i++)
  {
    p[i] = p[i-1] * P;
    h[i] = h[i-1] * P + str[i]; // str[i] 直接使用ascii码值当作hash值
	}
  
  while(m--)
  {
    int l1, r1, l2, r2;
    scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
    
    if (get(l1,r1) == get(l2,r2)) puts("Yes\n");
    else puts("No\n");
  }
  return 0;
}
```



