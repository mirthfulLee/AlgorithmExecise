// 1049 Counting Ones
// https://www.liuchuo.net/archives/2305
#include<iostream>
using namespace std;

int main(){
    int n, l, r, cur, ans = 0, exp = 1;
    cin >> n;
    while (n>=exp){
        l = n / (exp * 10);
        r = n % exp;
        cur = n / exp % 10;
        if (cur == 0)
            ans += l * exp;
        else if (cur == 1)
            ans += l * exp + r + 1;
        else
            ans += (l + 1) * exp;
        exp *= 10;
    }
    cout << ans;
}