// 1083 List Grades
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct student
{
    string name, id;
    int grade;
    bool operator<(const student &b) const
    {
        return grade > b.grade;
    }
};
vector<student> stuList;
int n, lo, hi, l, r, mid, p, q;
int main()
{
    cin >> n;
    stuList.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> stuList[i].name >> stuList[i].id >> stuList[i].grade;
    }
    cin >> lo >> hi;
    sort(stuList.begin(), stuList.end());
    // student range in [p, q)
    l = 0, r = n - 1;
    while (l < r)
    {
        mid = (l + r) / 2;
        if (hi >= stuList[mid].grade)
            r = mid;
        else
            l = mid + 1;
    }
    p = r;
    l = 0, r = n;
    while (l < r)
    {
        mid = (l + r) / 2;
        if (lo <= stuList[mid].grade)
            l = mid + 1; 
        else
            r = mid;
    }
    q = r;
    if (p >= q)
        cout << "NONE";
    for (int i = p; i < q; i++)
    {
        cout << stuList[i].name << ' ' << stuList[i].id << endl;
    }
}
