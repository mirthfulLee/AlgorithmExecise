// 1051 Pop Sequence
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool isValid(vector<int> &seq, int m, int n)
{
    stack<int> st;
    int cur = 1, cnt = 0;
    while (!st.empty() || cur <= n)
    {
        if (st.size() > m)
            return false;
        if (st.empty())
        {
            st.push(cur++);
            continue;
        }
        if (st.top() == seq[cnt])
        {
            st.pop();
            cnt++;
        }else if (st.top() < seq[cnt]){
            if (cur > n)
                return false;
            st.push(cur++);
        }else{
            return false;
        }
    }
    return true;
}
int main()
{
    int n, m, k;
    cin >> m >> n >> k;
    vector<int> seq(n);
    for (int t = 0; t < k; t++)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> seq[i];
        }
        printf("%s\n", isValid(seq, m, n) ? "YES" : "NO");
    }
}