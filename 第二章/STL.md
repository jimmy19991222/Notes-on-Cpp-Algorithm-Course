## C++ STL

### vector

变长数组，倍增思想

* size() 返回元素个数
* empty() 返回是否为空
* front() / back() 对头/队尾元素
* push_back() / pop_back() 在队尾插入元素 / 删除队尾元素
* begin() / end() 迭代器，begin()是第一个数， end()是最后一个数的后一个数
* 支持比较运算
* 支持随机选址

```c++
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  vector<int> a;
  for (int i = 0; i<10; i++) a.push_back(i);
  
  for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
  cout << endl;
  for (vector<int>::iterator i = a.begin(); i != a.end(); i++) cout << a[i] << " ";
  for (auto i = a.begin(); i != a.end(); i++) cout << *i << " "; // 可以解引用
  cout << endl;
  for (auto x: a) cout << x << " ";
  
  a[0], a[a.size()-1];
  
  // 支持比较大小
  vector<int> a(4,3), b(3,4);
  a<b;
  
  return 0;
}
```



### pair

* 一对
* 支持比较运算，按照字典序
* make_pair

```c++
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  pair<int, string> p;
  
  p.first, p.second;
  // 初始化
 	p = make_pair(10, "ljm");
  p = {20, "jyf"};
  
  pair<int, pair<int, int>> p;
  return 0;
}
```



### string

字符串

* subset()
* c_str()： 字符数组的起始地址

* size(), length()
* empty()
* clear()

```c++
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  string a = "ljm";
  a += "lovejy";
  a += 'f';
  
  a.substr(1, 2); // 第一个参数是开始位置，第二个是长度，当长度超过自动截断； 如果没有第二个参数，输出到最后。
  
  printf("%s\n", a.c_str());
  
  return 0;
}
```



### queue

队列

* push() 向队尾插入一个元素
* front() 返回队头元素
* back() 返回队尾元素
* pop() 弹出队元头素
* size(), empty()，没有clear函数，想清空就直接重新造一个

```c++
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
  queue<int> q;
  return 0;
}
```



### priority_queue

优先队列，堆，默认是大根堆

* push() 插入一个元素
* top() 返回堆顶元素
* pop() 弹出堆顶元素
* size(), empty()，没有clear函数，想清空就直接重新造一个

```c++
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int main()
{
  priority_queue<int> heap;
  
  // 怎么做小根堆？
  heap.push(-x); // 直接插入负值
  priority_queue<int, vector<int>, greater<int>)> heap; // 加入两个参数，定义成小根堆
  
  return 0;
}
```



### stack

栈

* push() 向栈顶插入元素
* top() 返回栈顶元素
* pop() 弹出栈顶元素
* size(), empty()，没有clear函数，想清空就直接重新造一个



```c++
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int main()
{
  priority_queue<int> heap;
  
  // 怎么做小根堆？
  heap.push(-x); // 直接插入负值
  priority_queue<int, vector<int>, greater<int>)> heap; // 加入两个参数，定义成小根堆
  
  return 0;
}
```



### deque

双端队列， 加强版的vector，但比一般的数组慢好几倍

* size()
* empty()
* clear()
* front()
* back()
* push_back()
* pop_back()
* push_front()
* pop_front()
* begin() / end()
* 支持随机选址

```c++
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <duque>

using namespace std;

int main()
{
	deque<int> q;
  
  return 0;
}
```



### set, map, multiset, multimap

基于平衡的二叉树（红黑树），动态维护有序序列

* size(), empty(), clear()
* begin(), end() ++, -- 返回前驱，后继 时间复杂度O(logn)

#### set / multiset

操作都是O(logn)

* insert() 插入一个数
* find() 查找一个数，没找到就会返回end()
* count() 返回一个数的个数，set只有0，1两种情况
* erase()
  * 输入一个数x， 删除所有x， O(k+logn), k是x的个数
  * 输入一个迭代器，删除这个迭代器
* lower_bound() 返回大于等于x的最小的数的迭代器
* upper_bound() 返回大于x的最小的数的迭代器

#### map / multimap

* insert() 插入一个pair
* erase() 输入一个pair或一个迭代器
* find()
* [] 时间复杂度是 O(logn), 而数组是 O(n)
* lower_bound() 返回大于等于x的最小的数的迭代器
* upper_bound() 返回大于x的最小的数的迭代器

```c++
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main()
{
	set<int> s; // 无重复元素
  multiset<int> s; // 允许重复元素出现
  
  map<string, int> a;
  a["ljm"] = 1;
  cout << a["ljm"] << endl;
  
  return 0;
}
```



### unordered_set, unordered_map, unordered_multiset, unordered_multimap, 哈希表

绝大部分操作，增删改查的时间复杂度是 O(1)

缺点是不支持 lower_bound, upper_bound，迭代器的 ++， --

```c++
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main()
{
	unordered_set<int> s; // 无重复元素
  unordered_multiset<int> s; // 允许重复元素出现
  
  return 0;
}
```



### bitset

压位

1024 bool 数组（1个字节）： 一共1024B = 1KB

每一个字节存8位



```c++
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main()
{
	bitset<10000> s; //表示一个n位的二进制数，<>中填写位数；
  ~s, &, |, ^; // 支持位运算
  >>, <<, ==, !=;
  []; // 取出某一位
  count(); // 返回有多少1
  any(); // 判断是否至少有一个1
  none(); // 判断是否全为0
  
  set(); // 把所有位置设置成1
  set(k, v); // 将第k位设置为v
  reset(); // 把所有位置设置成1
  flip(); // 等价于～
  flip(k); // 将第k位取反
  
  return 0;
}
```

