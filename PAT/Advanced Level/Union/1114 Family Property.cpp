// 1114 Family Property
// 并查集
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{
    int num, estateNum, totalArea, father, mother;
    vector<int> kids;
};
struct familyNode
{
    int id, num;
    double avgEstate, avgArea;
    bool operator < (const familyNode & b){
        return avgArea == b.avgArea ? (id < b.id) : (avgArea > b.avgArea);
    }
};

int N, fat, mon, id, k, kid, est, area;
vector<node> info(10010);
vector<int> family(10010);
vector<int> people(1010);

int head(int a)
{
    while (family[a] != a)
        a = family[a];
    return a;
}

void merge(int a, int b)
{
    int ha=head(a), hb=head(b);
    if (ha == hb)
        return;
    if (ha < hb)
    {
        family[hb] = ha;
        info[ha].num += info[hb].num;
        info[ha].estateNum += info[hb].estateNum;
        info[ha].totalArea += info[hb].totalArea;
    }
    else
    {
        family[ha] = hb;
        info[hb].num += info[ha].num;
        info[hb].estateNum += info[ha].estateNum;
        info[hb].totalArea += info[ha].totalArea;
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < 10000; i++)
    {
        info[i].num = 1;
        family[i] = i;
    }
    for (int i = 0; i < N; i++)
    {
        cin >> id;
        cin >> info[id].father >> info[id].mother >> k;
        people[i] = id;
        for (int j = 0; j < k; j++)
        {
            cin >> kid;
            info[id].kids.push_back(kid);
        }
        cin >> info[id].estateNum >> info[id].totalArea;
    }
    for (int i = 0; i < N;i++){
        id = people[i];
        if (info[id].father >= 0)
            merge(id, info[id].father);
        if (info[id].mother >= 0)
            merge(id, info[id].mother);
        for (int kid : info[id].kids)
            merge(id, kid);
    }
    vector<familyNode> families;
    for (int i = 0; i < 10000;i++){
        if (family[i] == i && info[i].estateNum > 0){
            familyNode temp;
            temp.id = i;
            temp.num = info[i].num;
            temp.avgArea = 1.0 * info[i].totalArea / info[i].num;
            temp.avgEstate = 1.0 * info[i].estateNum / info[i].num;
            families.push_back(temp);
        }
    }
    sort(families.begin(), families.end());
    cout << families.size() << endl;
    for (familyNode f : families){
        printf("%04d %d %.3f %.3f\n", f.id, f.num, f.avgEstate, f.avgArea);
    }
}