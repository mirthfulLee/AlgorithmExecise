// 1036 Boys vs Girls
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct student
{
    string name, id;
    int grade;
};
bool cmp(student &a, student &b){
    return a.grade < b.grade;
}

int main(){
    int n;
    student cur;
    char gender;
    vector<student> males, females;
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> cur.name >> gender >> cur.id >> cur.grade;
        if (gender == 'F')
            females.push_back(cur);
        else
            males.push_back(cur);
    }
    sort(males.begin(), males.end(), cmp);
    sort(females.begin(), females.end(), cmp);
    if (females.size())
        cout << females.back().name << ' ' << females.back().id << endl;
    else
        cout << "Absent" << endl;
    if (males.size())
        cout << males.front().name << ' ' << males.front().id << endl;
    else
        cout << "Absent" << endl;
    if (males.size() && females.size())
        cout << females.back().grade - males.front().grade;
    else
        cout << "NA";
}