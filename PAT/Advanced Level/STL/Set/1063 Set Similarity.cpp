// 1063 Set Similarity
#include<iostream>
#include<set>
using namespace std;

int main(){
    int n, m, k,t;
    set<int> num[55];
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> m;
        while(m--){
            cin >> t;
            num[i].insert(t);
        }
    }
    cin >> k;
    for (int i = 0; i < k;i++)
    {
        int p, q, common=0;
        cin >> p >> q;
        auto itp = num[p].begin(), itq = num[q].begin();
        while(itp != num[p].end() && itq!=num[q].end())
        {
            if (*itp == *itq){
                common++;
                itp++;
                itq++;
            }
            else if(*itp < *itq)
                itp++;
            else
                itq++;
        }
        double result = 100.0 * common / (num[p].size() + num[q].size() - common);
        printf("%.1f%%\n", result);
    }
}