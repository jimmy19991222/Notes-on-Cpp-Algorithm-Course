// 大整数相加、相减、大整数乘小整数，大整数除以小整数
// Ci = Ai+ Bi+ t(i-1)

//高精度加法

#include <iostream>
#include <vector>

using namespace std;

const int N = 1e6 + 10;

// 加入引用是为了效率，引用不会拷贝整个数组
vector<int> add(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || i < B.size(); i++)
    {
        if (i < A.size())
            t += A[i];
        if (i < B.size())
            t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if (t)
        C.push_back(1);
    return C;
}

int main()
{
    string a, b;
    vector<int> A, B;

    cin >> a >> b;
    // 两个字符相减，得到ASCII码，其实转换成了整型
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--)
        B.push_back(b[i] - '0');

    auto C = add(A, B);

    for (int i = C.size() - 1; i >= 0; i--)
        printf("%d", C[i]);
    return 0;
}

// 高精度减法

bool cmp(vector<int> &A, vector<int> &B)
{
    if (A.size() != B.size())
        return A.size() > B.size();
    for (int i = A.size() - 1; i >= 0; i--)
    {
        if (A[i] != B[i])
            return A[i] > B[i];
    }
    return 1;
}

vector<int> sub(vector<int> A, vector<int> B)
{
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i++)
    {
        t = A[i] - t;
        if (i < B.size())
            t -= B[i];
        C.push_back((t + 10) % 10);
        // 如果 t>0 （t+10）%10 = t
        // 如果 t<0 （t+10）%10 = t+10

        if (t < 0)
            t = 1;
        else
            t = 0;
    }
    while (C.size() > 1 && C.back() == 0)
        C.pop_back(); //去掉前导零
    return C;
}

int main()
{
    string a, b;
    vector<int> A, B;

    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--)
        B.push_back(b[i] - '0');

    if (cmp(A, B))
    {
        auto C = sub(A, B);

        for (int i = C.size() - 1; i >= 0; i--)
            printf("%d", C[i]);
    }
    else
    {
        auto C = sub(B, A);
        printf("-");
        for (int i = C.size() - 1; i >= 0; i--)
            printf("%d", C[i]);
    }
    return 0;
}

// 高精度乘法

#include <iostream>
#include <vector>

using namespace std;

vector<int> mul(vector<int> &A, int b)
{
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || t; i++)
    {
        if (i < A.size())
            t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    return C;
}

int main()
{
    string a;
    int b;

    cin >> a >> b;

    vector<int> A;
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');

    auto C = mul(A, b);

    for (int i = C.size() - 1; i >= 0; i--)
        printf("%d", C[i]);
    return 0;
}

// 高精度除法 A/b,商是C，余数是r

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> div(vector<int> A, int b, int &r) //r是引用过去的
{
    vector<int> C;
    r = 0;
    for (int i = A.size()-1;i>=0;i--)
    {
        r = r * 10 + A[i];
        C.push_back(r/b);
        r %= b;
    }
    reverse(C.begin(),C.end());
    while(C.size()>1 && C.back()==0) C.pop_back();
    return C;
}

int main()
{
    string a;
    int b;
    cin >> a >> b;
    vector<int> A, C;
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');

    int r;

    C = div(A, b, r);

    for (int i = C.size() - 1; i >= 0; i--)
        printf("%d", C[i]);
    cout << endl
         << r << endl;
    return 0;
}

