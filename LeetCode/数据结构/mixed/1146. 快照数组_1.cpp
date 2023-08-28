// 1146. 快照数组
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class SnapshotArray {
 private:
  // vector for each index
  // map <snapTime, val>
  // replace vector with unordered_map(hashmap) could get better
  // performance(avoid unnecessary memory aloocate)
  // the snapTime is ascending, so could replace map with 
  // vector<pair> + binary search 
  vector<map<int, int>> snapshots;
  int snapTime = 0;

 public:
  SnapshotArray(int length) {
    // this step is time consuming
    snapshots = vector<map<int, int>>(length, map<int, int>());
  }

  void set(int index, int val) { snapshots[index][snapTime] = val; }

  int snap() { return snapTime++; }

  int get(int index, int snap_id) {
    auto it = snapshots[index].upper_bound(snap_id);
    return it == snapshots[index].begin() ? 0 : (--it)->second;
  }
};

int main() {
  SnapshotArray snapshotArr = SnapshotArray(3);
  snapshotArr.set(0, 5);       // 令 array[0] = 5
  cout << snapshotArr.snap();  // 获取快照，返回 snap_id = 0
  cout << snapshotArr.snap();  // 获取快照，返回 snap_id = 1
  cout << snapshotArr.snap();  // 获取快照，返回 snap_id = 2
  snapshotArr.set(0, 6);
  cout << snapshotArr.get(
      0, 0);  // 获取 snap_id = 0 的快照中 array[0] 的值，返回 5
}