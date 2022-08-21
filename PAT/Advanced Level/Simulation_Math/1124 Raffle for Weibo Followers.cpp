// 1124 Raffle for Weibo Followers
#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;

int M, N, S, cur;
set<string> winners;
vector<string> forward_list(1010);

int main()
{
    cin >> M >> N >> S;
    for (int i = 1; i <= M; i++)
    {
        cin >> forward_list[i];
    }
    if (M < S)
    {
        cout << "Keep going...";
        return 0;
    }
    for (int i = S; i <= M; i += N)
    {
        while (i <= M && winners.find(forward_list[i]) != winners.end())
            i++;
        if (i <= M)
        {
            cout << forward_list[i] << endl;
            winners.insert(forward_list[i]);
        }
    }
    return 0;
}
