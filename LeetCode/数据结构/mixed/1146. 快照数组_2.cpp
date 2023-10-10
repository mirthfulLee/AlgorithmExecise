// 1146. 快照数组
#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

class SnapshotArray {
 private:
  unordered_map<int, map<int, int>> snapshots;
  int snapTime = 0;

 public:
  SnapshotArray(int length) {}

  void set(int index, int val) { snapshots[index][snapTime] = val; }

  int snap() { return snapTime++; }

  int get(int index, int snap_id) {
    auto it = snapshots[index].upper_bound(snap_id);
    return it == snapshots[index].begin() ? 0 : (--it)->second;
  }
};

