// 1158 Telefraud Detection
#include <iostream>
#include <vector>
using namespace std;

// 在栈区开过大的数组会报错Segment Fault
int k, n, m, caller, receiver, dur, call[1010][1010];
bool suspect[1010];
vector<int> gangs(1010, -1);

int head(int k)
{
    while (gangs[k] != k)
        k = gangs[k];
    return k;
}

void merge(int a, int b)
{
    int ha = head(a), hb = head(b);
    if ( ha < hb )
        gangs[hb] = ha;
    else
        gangs[ha] = hb;
}

int main()
{
    cin >> k >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> caller >> receiver >> dur;
        call[caller][receiver] += dur;
    }
    bool haveSuspect = false;
    for (int i = 1; i <= n; i++)
    {
        int calling = 0, callback = 0;
        for (int j = 1; j <= n; j++)
        {
            if (call[i][j] && call[i][j] <= 5)
            {
                calling++;
                if (call[j][i])
                    callback++;
            }
        }
        if (calling > k && calling >= 5 * callback){
            haveSuspect = true;
            suspect[i] = true;
        }
    }
    if (!haveSuspect){
        // FIXME: 注意换行符
        printf("None\n");
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        if (suspect[i])
        {
            if (gangs[i] == -1)
                gangs[i] = i;
            for (int j = 1; j <= i - 1; j++)
                if (suspect[j] && call[i][j] && call[j][i])
                    merge(i, j);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (gangs[i] == i)
        {
            printf("%d", i);
            for (int j = i + 1; j <= n; j++)
                if (suspect[j] && head(j) == i)
                    printf(" %d", j);
            printf("\n");
        }
    }
}