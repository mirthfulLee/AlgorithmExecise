//
// Created by 木子又欠 on 2020/9/19.
//

#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int main(){
    int n, m, pos, dir, tmp;
    cin >> n;
    std::list<int> stu_list;
    std::list<int>::iterator stu_ptr[100005], it;
    bool rm[100005] = {false};
    stu_list.push_back(1);
    it = stu_list.begin();
    stu_ptr[1] = it;
    for (int i = 2; i <= n; i++) {
        cin >> pos >> dir;
        it = stu_ptr[pos];
        advance(it, dir);
        stu_list.insert(it, i);
        //pay attention to the position of iterator after the insert operation
        //that the reason for "--it"
        stu_ptr[i] = --it;
    }
    //remove m students
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> tmp;
        rm[tmp] = true;
    }
    //output
    for (it=stu_list.begin(); it!=stu_list.end(); ++it){
        if (!rm[*it]) std::cout << *it << ' ';
    }
    std::cout << '\n';
    return 0;
}
