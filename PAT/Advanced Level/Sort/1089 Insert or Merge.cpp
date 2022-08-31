// 1089 Insert or Merge
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool vectorCmp(vector<int> &a, vector<int> &b)
{
    for (int i = 0; i < a.size();i++)
        if (a[i] != b[i])
            return false;
    return true;
}

vector<int> insertSort(vector<int> nums, vector<int> &target)
{
    int i;
    bool flag = false;
    for (i = 1; i < nums.size() && !flag;i++){
        int j = i - 1, cur = nums[i];
        while (j>=0 && nums[j] > cur) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = cur;
        flag = vectorCmp(nums, target);
    }
    if (!flag){
        vector<int> empty;
        return empty;
    }else{
        int j = i - 1, cur = nums[i];
        while (j>=0 && nums[j] > cur) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = cur;
        return nums;
    }
}

vector<int> mergeSort(vector<int> nums, vector<int> &target)
{
    int gs = 1;
    bool flag = false;
    while (gs < nums.size() && !flag){
        int groupNum = nums.size() / gs;
        auto it = nums.begin();
        for (int i=0;i<groupNum;i++) {
            sort(it, it + gs);
            it = it + gs;
        }
        sort(it, nums.end());
        flag = vectorCmp(nums, target);
        gs *= 2;
    }
    if (!flag){
        vector<int> empty;
        return empty;
    }else{
        int groupNum = nums.size() / gs;
        auto it = nums.begin();
        for (int i=0;i<groupNum;i++) {
            sort(it, it + gs);
            it = it + gs;
        }
        sort(it, nums.end());
        return nums;
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n), target(n), result;
    for (int i = 0; i < n;i++)
        cin >> nums[i];
    for (int i = 0; i < n;i++)
        cin >> target[i];
    result = insertSort(nums, target);
    if (result.size()){
        cout << "Insertion Sort" << endl;
        for (int i = 0; i < n;i++){
            if (i>0)
                cout << ' ';
            cout << result[i];
        }
    }
    else{
        result = mergeSort(nums, target);
        cout << "Merge Sort" << endl;
        for (int i = 0; i < n;i++){
            if (i>0)
                cout << ' ';
            cout << result[i];
        }
    }
}