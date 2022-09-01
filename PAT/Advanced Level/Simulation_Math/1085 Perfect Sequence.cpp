// 1085 Perfect Sequence
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, p;
vector<long long> nums;
int main(){
    cin >> n >> p;
    nums.resize(n);
    for (int i = 0; i < n;i++)
        cin >> nums[i];
    sort(nums.begin(), nums.end());
    int i = 0, maxL = 0;
    for (int j = 0; j < n;j++){
        while(nums[j]>nums[i] * p)
            i++;
        if (j-i+1 > maxL)
            maxL = j - i + 1;
    }
    cout << maxL;
}