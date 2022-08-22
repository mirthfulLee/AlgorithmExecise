// 1057 Stack
// hash or 多层桶结构
#include <iostream>
#include<stack>
#include <string>
using namespace std;

int bucket[1005][105], cnt[1005];

void bucket_push(int key){
    int l1 = key / 100, l2 = key % 100;
    cnt[l1]++;
    bucket[l1][l2]++;
}

void bucket_pop(int key){
    int l1 = key / 100, l2 = key % 100;
    cnt[l1]--;
    bucket[l1][l2]--;
}

int find_kth_value(int k){
    int l1 = 0, l2 = 0, sum = 0;
    while (sum+cnt[l1] < k)
        sum += cnt[l1++];
    while (sum + bucket[l1][l2]<k)
        sum += bucket[l1][l2++];
    return 100 * l1 + l2;
}

int main()
{
    int N, l, r = 0, t;
    string s;
    stack<int> st;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        if (s.compare("Push") == 0)
        {
            cin >> t;
            st.push(t);
            bucket_push(t);
        }
        if (s.compare("Pop") == 0)
        {
            if (st.empty())
                printf("Invalid\n");
            else{
                printf("%d\n", st.top());
                bucket_pop(st.top());
                st.pop();
            }
        }
        if (s.compare("PeekMedian") == 0)
        {
            if (st.empty())
                printf("Invalid\n");
            else
            {
                printf("%d\n", find_kth_value((st.size() + 1) / 2));
            }
        }
    }
}