// 1125 Chain the Ropes
// 贪心算法
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> ropes(10010);
int N, sum;

int main(){
    cin >> N;
    for (int i = 0; i < N;i++){
        cin >> ropes[i];
    }
    sort(ropes.begin(), ropes.begin() + N);
    sum = (ropes[0] + ropes[1]) / 2;
    for (int i = 2; i < N;i++){
        sum = (sum + ropes[i]) / 2;
    }
    cout << sum;
}