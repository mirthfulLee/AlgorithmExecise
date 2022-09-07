// 202109-1 数组推导
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, sumB, minSum;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n;i++){
        cin >> b[i];
    }
    sumB = b[0], minSum = b[0];
    for (int i = 1; i < n;i++){
        if (b[i]>b[i-1])
            minSum += b[i];
        sumB += b[i];
    }
    printf("%d\n%d", sumB, minSum);
}