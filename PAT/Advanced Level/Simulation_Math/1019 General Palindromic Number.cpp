//
// Created by 木子又欠 on 2021/2/27.
//

#include <iostream>
#include <vector>
using namespace std;


int main(){
    int N, b, t, flag = 1;
    cin >> N >> b;
    vector<int> a;
    t = N;
    while (t) {
        a.push_back(t % b);
        t /= b;
    }
    for (int i = 0; i < a.size()/2; i++) {
        if (a[i] != a[a.size() - 1 - i]) {
            flag = 0;
        }
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    for (int i = a.size() - 1; i > 0; i--) {
        cout << a[i] << ' ';
    }
    cout << a[0];
    return 0;
}