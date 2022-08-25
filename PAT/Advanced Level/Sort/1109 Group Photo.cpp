// 1109 Group Photo
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct student
{
    int height;
    string name;
    bool operator<(const student &b)
    {
        return height == b.height ? name < b.name : height > b.height;
    }
};
int k, n, h, col;
string form[5010], s;
vector<student> list(10010);

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> list[i].name >> list[i].height;
    }
    sort(list.begin(), list.begin() + n);
    col = n / k;
    int highest = 0;
    for (int r = 0; r < k; r++)
    {
        int m = r == 0 ? n - col * (k - 1) : col;
        int mid = m / 2;
        form[mid] = list[highest].name;
        for (int i = 1; i < m; i++)
            if (i % 2)
                form[mid - (i + 1) / 2] = list[highest + i].name;
            else
                form[mid + (i + 1) / 2] = list[highest + i].name;
        highest += m;

        cout << form[0];
        for (int i = 1; i < m; i++)
            cout << ' ' << form[i];
        cout << endl;
    }
}