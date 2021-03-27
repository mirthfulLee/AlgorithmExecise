//
// Created by 木子又欠 on 2020/10/17.
//

#include <iostream>
using namespace std;

int a[7][7] = {
        {1,1,0,0,0,1,0},
        {1,1,1,0,0,0,1},
        {0,1,1,1,0,0,1},
        {0,0,1,1,1,0,0},
        {0,0,0,1,1,1,1},
        {1,0,0,0,1,1,1},
        {0,1,1,0,1,1,1}
};
int leader, group[7], chosen[7], total = 0;

int legal(){
    leader = -1;
    for (int i = 0; i < 7; i++) group[i] = i;
    for (int i = 0; i < 7; i++)
        if (chosen[i]) {
            leader=i;
            break;
        }
    if (leader<0) return 0;

    for (int i=0;i<7;i++){
        if (chosen[i]){
            for (int j = i+1; j < 7; j++) {
                if (chosen[j]&&a[i][j]) group[j] = group[i];
            }
        }
    }

    for (int i = 0; i < 7; i++) {
        if (chosen[i]&&group[i]!=leader) return 0;
    }
    return 1;
}

void attempt(int index){
    if (index==7) {
        total+=legal();
        return;
    }
    chosen[index] = 0;
    attempt(index + 1);
    chosen[index] = 1;
    attempt(index + 1);
}

int main(){
    attempt(0);
    cout<<total;
    return 0;
}