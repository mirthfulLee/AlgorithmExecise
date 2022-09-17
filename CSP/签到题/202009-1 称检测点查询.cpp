// 202009-1 称检测点查询
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
struct point
{
    int x, y, id;
    double dist;
};
bool cmp(point &a, point &b){
    return a.dist == b.dist ? a.id < b.id : a.dist < b.dist;
}
int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<point> p(n);
    for (int i = 0; i < n;i++){
        cin >> p[i].x >> p[i].y;
        p[i].dist = pow(p[i].x - x, 2) + pow(p[i].y - y, 2);
        p[i].id = i+1;
    }
    sort(p.begin(), p.end(), cmp);
    for (int i = 0; i < 3;i++)
        cout << p[i].id << endl;
}