// 1162. 地图分析
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
 private:
  static constexpr int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
  typedef struct Node {
    int x, y;
  } Node;
  queue<Node> nodeQ;
  bool newOcean(Node area, vector<vector<int>>& dis, int curDis) {
    int n = dis.size();
    if (area.x >= 0 && area.x < n && area.y >= 0 && area.y < n &&
        dis[area.x][area.y] == -1) {
      dis[area.x][area.y] = curDis + 1;
      nodeQ.push(area);
      return true;
    } else
      return false;
  }

 public:
  int maxDistance(vector<vector<int>>& grid) {
    nodeQ = queue<Node>();
    int maxD = 0, n = grid.size(), cnt = 0;
    vector<vector<int>> dis(n, vector<int>(n, -1));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          nodeQ.push({i, j});
          dis[i][j] = 0;
          ++cnt;
        }
      }
    }
    if (cnt == 0 || cnt == n * n) {
      return -1;
    }
    Node cur, area;
    while (cnt < n * n) {
      cur = nodeQ.front();
      nodeQ.pop();
      for (int i = 0; i < 4; i++) {
        if (newOcean({cur.x + dx[i], cur.y + dy[i]}, dis, dis[cur.x][cur.y])) {
          cnt++;
        }
      }
    }
    cur = nodeQ.back();
    return dis[cur.x][cur.y];
  }
};

int main() {
  vector<vector<int>> grid = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
  Solution sol;
  cout << sol.maxDistance(grid);
}