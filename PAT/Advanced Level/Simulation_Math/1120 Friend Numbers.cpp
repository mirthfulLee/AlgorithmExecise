// 1120 Friend Numbers
#include<iostream>
#include<vector>
#include<set>
using namespace std;

int digitSum(int a){
    int sum = 0;
    while (a){
        sum += a % 10;
        a /= 10;
    }
    return sum;
}
int main(){
    int n, num;
    set<int> cnt;
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> num;
        cnt.insert(digitSum(num));
    }
    cout << cnt.size() << endl;
    auto it = cnt.begin();
    cout << *it;
    for (it++; it != cnt.end();it++){
        cout << ' ' << *it;
    }
}