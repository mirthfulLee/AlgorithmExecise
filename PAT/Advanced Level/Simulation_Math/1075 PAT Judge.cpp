// 1075 PAT Judge
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct person
{
    int id, perfectFinished, totalGrade;
    bool valid;
    vector<int> grades;
};
bool cmp(person &a, person &b)
{
    if (!a.valid)
        return false;
    if (a.totalGrade == b.totalGrade)
    {
        if (a.perfectFinished == b.perfectFinished)
            return a.id < b.id;
        else
            return a.perfectFinished > b.perfectFinished;
    }
    else
        return a.totalGrade > b.totalGrade;
}

int n, m, k, id, problem, score;
vector<person> records;
vector<int> scores;

int main()
{
    cin >> n >> k >> m;
    records.resize(n + 1);
    scores.resize(k + 1);
    for (int i = 1; i <= k; i++)
        cin >> scores[i];
    for (int i = 1; i <= n; i++)
    {
        records[i].id = i;
        records[i].grades.resize(k + 1, -2);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> id >> problem >> score;
        if (score >= 0)
            records[id].valid = true;
        if (score < 0)
            score = 0;
        records[id].grades[problem] = max(records[id].grades[problem], score);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (records[i].grades[j] > 0)
                records[i].totalGrade += records[i].grades[j];
            if (records[i].grades[j] == scores[j])
                records[i].perfectFinished++;
        }
    }
    sort(++records.begin(), records.end(), cmp);
    int rank = 1;
    for (int i = 1; i <= n; i++)
    {
        if (i > 1 && records[i].totalGrade < records[i - 1].totalGrade)
            rank = i;
        if (!records[i].valid)
            break;
        printf("%d %05d %d", rank, records[i].id, records[i].totalGrade);
        for (int j = 1; j <= k; j++)
        {
            if (records[i].grades[j] >= 0)
                printf(" %d", records[i].grades[j]);
            else
                printf(" -");
        }
        printf("\n");
    }
}
