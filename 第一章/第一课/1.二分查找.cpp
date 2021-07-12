// 整数二分，将数组分为两个部分，左边不满足，右边满足
// 1.mid = l + r + 1/2 
// check(x) x左边满足，右边不满足
// if(check(mid)): true [mid,r] l=mid;
// false [l,mid-1] r=mid-1;

// 2. mid = l+r/2
// check(x) x左边不满足，右边满足
// if (check(mid)) true? [l,mid] r=mid
// false [mid+1,r] l=mid+1

# include <iostream>
using namespace std;

int check(int x)
{
    return 0;
}

// 区间[l,r]被划分成[l,mid]和[mid+1,r]时使用：
// 右边都满足，左边都不满足
int bsearch_1(int l,int r)
{
    while (l<r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid +1;
    }
    return l;
}

// 区间[l,r] 被划分成[l,mid-1]和[mid,r]时使用：
// 左边都满足，右边都满足
int bsearch_2(int l,int r)
{
    while(l<r)
    {
        int mid = l + r + 1 >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}

int main()
{
    return 0;
}