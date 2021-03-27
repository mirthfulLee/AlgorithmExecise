//
// Created by 木子又欠 on 2020/9/19.
//

#include <iostream>
#include <algorithm>
#include <list>

using namespace std;


int main(){
    int n, m;
    cin >> n >> m;
    std::list<int> cycle;
    std::list<int> ans;
    for (int i = 1; i <= n; i++) {
        cycle.push_back(i);
    }
    int size = n, ptr = 0;
    while (cycle.size() > 0) {
        std::list<int>::iterator it = cycle.begin();
        ptr = (ptr + m - 1) % size;
        advance(it, ptr);
        ans.push_back(*it);
        cycle.erase(it);
        size--;
    }
    for (std::list<int>::iterator item = ans.begin(); item != ans.end(); ++item) {
        cout << *item << " ";
    }
    return 0;
}

