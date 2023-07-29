// 2657. 找到两个数组的前缀公共数组
// 用set或者vector（桶）可以实现， 见 数据结构/set/2657. 找到两个数组的前缀公共数组.cpp
// 由于1 <= A.length == B.length == n <= 50， n较小，可以用位运算
// 用位运算表示集合，两个数的 AND 就代表集合的交集，交集的大小就是二进制中1的个数。

#include<vector>
using namespace std;

vector<int> findThePrefixCommonArray(vector<int> &a, vector<int> &b) {
    int n = a.size();
    vector<int> ans(n);
    long long p = 0, q = 0;
    for (int i = 0; i < n; ++i) {
        p |= 1LL << a[i];
        q |= 1LL << b[i];
        ans[i] = __builtin_popcountll(p & q);
    }
    return ans;
}

// 作者：endlesscheng
// 链接：https://leetcode.cn/problems/find-the-prefix-common-array-of-two-arrays/solution/li-yong-wei-yun-suan-jia-su-pythonjavacg-uzme/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。