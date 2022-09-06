// 1028 List Sorting
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct student
{
    int id, grade;
    string name;
};

bool cmp1(student &a, student &b)
{
    return a.id < b.id;
}
bool cmp2(student &a, student &b)
{
    int cmp = a.name.compare(b.name);
    return cmp <= 0 || cmp == 0 && a.id < b.id;
}
bool cmp3(student &a, student &b)
{
    return a.grade == b.grade ? a.id < b.id : a.grade < b.grade;
}
int main()
{
    int n, c;
    vector<student> list;
    cin >> n >> c;
    list.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> list[i].id >> list[i].name >> list[i].grade;
    }
    switch (c)
    {
    case 1:
        sort(list.begin(), list.end(), cmp1);
        break;
    case 2:
        sort(list.begin(), list.end(), cmp2);
        break;
    case 3:
        sort(list.begin(), list.end(), cmp3);
        break;
    default:
        break;
    }
    for (int i = 0; i < n; i++)
        printf("%06d %s %d\n", list[i].id, list[i].name.c_str(), list[i].grade);
}