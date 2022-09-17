// 202009-2 风险人群筛查
#include<iostream>
#include<vector>
using namespace std;
int n, k, t, xl, yl, xr, yr, passed = 0, stayed = 0, x, y;
int main()
{
    cin >> n >> k >> t >> xl >> yl >> xr >> yr;
    for (int i = 0; i < n;i++){
        int conti = 0;
        bool p = false, s = false;
        for (int j = 0; j < t;j++){
            cin >> x >> y;
            if (x>=xl && x<=xr && y>=yl && y<= yr)
                conti++, p = true;
            else
                conti = 0;
            if (conti >= k)
                s = true;
        }
        if (p)
            passed++;
        if (s)
            stayed++;
    }
    cout << passed << endl
         << stayed;
}