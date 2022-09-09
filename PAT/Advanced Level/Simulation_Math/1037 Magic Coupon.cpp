// 1037 Magic Coupon
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int couponNum, productNum;
    cin >> couponNum;
    vector<int> c(couponNum);
    for (int i = 0; i < couponNum; i++)
        cin >> c[i];
    cin >> productNum;
    vector<int> p(productNum);
    for (int i = 0; i < couponNum; i++)
        cin >> p[i];
    sort(c.begin(), c.end());
    sort(p.begin(), p.end());
    int cl = 0, cr = couponNum - 1, pl = 0, pr = productNum - 1, sum = 0;
    while (cr >= 0 && pr >= 0 && c[cr] > 0 && p[pr] > 0)
        sum += c[cr--] * p[pr--];
    
    while (cl <= cr && pl <= pr && c[cl] < 0 && p[pl] < 0)
        sum += c[cl++] * p[pl++];
    cout << sum;
}