// 1080 Graduate Admission
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct applicant
{
    int id, Ge, Gi, school;
    int choice[5];
    bool operator<(const applicant &b)
    {
        return (Ge + Gi != b.Ge + b.Gi) ? Ge + Gi > b.Ge + b.Gi : Ge > b.Ge;
    }
};

int N, M, k;
vector<applicant> apps(40000);
vector<int> quota(110);
set<int> cadicate[110];

int main()
{
    cin >> N >> M >> k;
    for (int i = 0; i < M; i++)
        cin >> quota[i];
    for (int i = 0; i < N; i++)
    {
        apps[i].id = i;
        cin >> apps[i].Ge >> apps[i].Gi;
        for (int j = 0; j < k; j++)
            cin >> apps[i].choice[j];
    }
    sort(apps.begin(), apps.begin() + N);
    cadicate[apps[0].choice[0]].insert(apps[0].id);
    apps[0].school = apps[0].choice[0];
    for (int i = 1; i < N; i++)
    {
        applicant cur = apps[i];
        int c = 0;
        while (c < k && !(cadicate[cur.choice[c]].size() < quota[cur.choice[c]] || (!(apps[i - 1] < cur) && cur.choice[c] == apps[i - 1].school)))
            c++;
        if (c < k)
        {
            cadicate[cur.choice[c]].insert(cur.id);
            apps[i].school = cur.choice[c];
        }
        else
        {
            apps[i].school = -1;
        }
    }
    for (int i = 0; i < M; i++)
    {
        if (!cadicate[i].empty())
        {
            auto it = cadicate[i].begin();
            printf("%d", *it);
            for (it++; it != cadicate[i].end(); it++)
                printf(" %d", *it);
        }
        printf("\n");
    }
}
