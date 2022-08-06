// 快速排序步骤：(分治思想)
// 1.确定分界点： q[l] q[(l+r)/2] q[r]随机
// 2. 调整范围 ，左边小于x， 右边大于x
// 3. 递归处理左右两端

// 2的实现方法：开辟两个新数组 a[] ,b[]，用来存放小于x和大于x的数
// 再将他们拼接起来

// 2的优雅的实现方法：开辟左右指针i，j
// 如果 q[i]<x 就说明此时的 i 应该放在x的左边， 让 i++
// 直到 q[i]>x 说明这个q[i]应该在x右边，停止操作i
// 同样的操作 j，直到 q[j]<x 前 j--
// 此时，i,j 所指向的数都错位了，此时 swap(a[i],a[j])，此时i，j的位置正确了
// 再将 i,j 移动，直到 i,j 相遇（穿过），区间分开成功

// 3,1,2,3,5 x=3 i=0 j=4
// 3,1,2,3,5 x=3 i=0 j=3
// 3,1,2,3,5 x=3 i=1 j=2
// 3,1,2,3,5 x=3 i=3 j=2

// 含有边界问题 需要背诵模板

#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int n;
int q[N];

void quick_sort(int q[], int l, int r)
{
    if (l >= r)
        return;

<<<<<<< HEAD
    int x = (q[l] + q[r])/2, i = l - 1, j = r + 1;
=======
    int x = q[l], i = l - 1, j = r + 1;
>>>>>>> 0740c9e61e3c68063268b3ee95a7bd1a3a6e4aa4

    while (i < j)
    {
        do
            i++;
        while (q[i] < x);
        do
            j--;
        while (q[j] > x);
        if (i < j)
            swap(q[i], q[j]);
    }

    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

int main()
{
    printf("请输入数组个数");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("请依次输入需要排序的数组的元素");
        scanf("%d", &q[i]);
    }

    quick_sort(q, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d\t", q[i]);

    return 0;
}

