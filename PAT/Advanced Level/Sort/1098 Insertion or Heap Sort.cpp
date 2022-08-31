// 1098 Insertion or Heap Sort
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool vectorCmp(vector<int> &a, vector<int> &b)
{
    for (int i = 0; i < a.size(); i++)
        if (a[i] != b[i])
            return false;
    return true;
}

vector<int> insertSort(vector<int> nums, vector<int> &target)
{
    int i;
    bool flag = false;
    for (i = 1; i < nums.size() && !flag; i++)
    {
        int j = i - 1, cur = nums[i];
        while (j >= 0 && nums[j] > cur)
        {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = cur;
        flag = vectorCmp(nums, target);
    }
    if (!flag)
    {
        vector<int> empty;
        return empty;
    }
    else
    {
        int j = i - 1, cur = nums[i];
        while (j >= 0 && nums[j] > cur)
        {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = cur;
        return nums;
    }
}

int leftKid(int i)
{
    return 2 * i + 1;
}
int rightKid(int i)
{
    return 2 * i + 2;
}
void swap(vector<int> &nums, int i, int j)
{
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}
void shiftDown(vector<int> &nums, int p, int n)
{
    int maxId = p;
    if (leftKid(p)<n && nums[leftKid(p)]>nums[maxId])
        maxId = leftKid(p);
    if (rightKid(p)<n && nums[rightKid(p)]>nums[maxId])
        maxId = rightKid(p);
    if (maxId != p){
        swap(nums, p, maxId);
        shiftDown(nums, maxId, n);
    }
}
void buildHeap(vector<int> &nums)
{
    int n = nums.size();
    for (int i = n / 2; i >= 0;i--){
        shiftDown(nums, i, n);
    }
}

vector<int> heapSort(vector<int> nums, vector<int> &target)
{
    int n = nums.size();
    bool flag = false;
    buildHeap(nums);
    while (n>1 && !flag){
        swap(nums, 0, n-1);
        n--;
        shiftDown(nums, 0, n);
        flag = vectorCmp(nums, target);
    }
    if (!flag)
    {
        vector<int> empty;
        return empty;
    }
    else
    {
        swap(nums, 0, n-1);
        n--;
        shiftDown(nums, 0, n);
        return nums;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n), target(n), result;
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    for (int i = 0; i < n; i++)
        cin >> target[i];
    result = insertSort(nums, target);
    if (result.size())
    {
        cout << "Insertion Sort" << endl;
        for (int i = 0; i < n; i++)
        {
            if (i > 0)
                cout << ' ';
            cout << result[i];
        }
    }
    else
    {
        result = heapSort(nums, target);
        cout << "Heap Sort" << endl;
        for (int i = 0; i < n; i++)
        {
            if (i > 0)
                cout << ' ';
            cout << result[i];
        }
    }
}