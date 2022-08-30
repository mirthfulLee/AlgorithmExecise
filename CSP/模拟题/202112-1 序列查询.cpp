// 	202112-1 序列查询
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, up, cur, sum=0;
    cin >> n >> up;
    vector<int> a(n+1);
    a[0] = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n;i++){
        sum += (a[i] - a[i - 1]) * (i - 1);
    }
    sum += (up - a[n]) * n;
    cout << sum;
}