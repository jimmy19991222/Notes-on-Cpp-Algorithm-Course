// 归并排序：（分治思想）
// 1. 确定分界点 mid = (l+r)/2
// 2. 递归排序 left,right
// 3. 将两个有序的数组归并——合二为一

// 3的实现：（双指针算法）
// i,j分别指向两个有序数组的第一个（min）
// 值更小的将值加到目标数组中，指针++
// 直到两个指针有一个到最后了
// 将另一个数组的剩余值直接加到目标数组的最后，返回

// 排序方法的稳定：
// 归并排序是稳定的，快速排序是不稳定的
// 原数列 有两个值是相同的 如果排序后两个值的位置不发生改变，则称算法稳定
// 使快排稳定的方法：a ——（a,i）变为双关键字排序

#include <iostream>
using namespace std;

const int N = 1000010;

int n, q[N], temp[N];

void merge_sort(int q[], int l, int r)
{
    if (l >= r)
        return;
    int mid = l + r >> 1;
    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (q[i] <= q[j])
            temp[k++] = q[i++];
        else
            temp[k++] = q[j++];
    while (i <= mid) 
        temp[k++] = q[i++];
    while (j <= r)
        temp[k++] = q[j++];

    for (i = l, j = 0; i <= r; i++, j++)
        q[i] = temp[j];
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &q[i]);
    }

    merge_sort(q, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d", q[i]);
    }
    return 0;
}
