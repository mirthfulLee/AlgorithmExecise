// 1065 A+B and C (64bit)
#include <iostream>
using namespace std;

int main()
{
    // FIXME: 有一个点没过
    int n;
    long long a, b, c, sa, sb, sc, la, lb, lc;
    bool result;
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> a >> b >> c;
        sa = a / 0x0fffffff;
        sb = b / 0x0fffffff;
        sc = c / 0x0fffffff;
        la = a % 0x0fffffff;
        lb = b % 0x0fffffff;
        lc = c % 0x0fffffff;
        printf("%lld, %lld;  %lld, %lld\n", sa, sb, la, lb);
        result = (sa + sb > sc) || (sa + sb == sc && la + lb > lc);
        printf("Case #%d: %s\n", i, result ? "true" : "false");
    }
}