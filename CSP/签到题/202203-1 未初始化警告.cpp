// 202203-1 未初始化警告
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, k, cnt = 0, x, y;
    cin >> n >> k;
    
    vector<bool> left(n + 1, false);
    left[0] = true;
    for (int i = 0; i < k;i++){
        cin >> x >> y;
        if (!left[y])
            cnt++;
        left[x] = true;
    }
    cout << cnt;
}