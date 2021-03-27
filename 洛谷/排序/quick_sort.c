//
// Created by 木子又欠 on 2020/8/18.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int less(int m,int n);
void sort(int lo,int hi);
int partition(int lo,int hi);
void exch(int i,int j);

int a[200];
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d",&a[i]);
    }
    sort(0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ",a[i]);
    }
}

int less(int m,int n){
    if (m<n){
        return 1;
    }else return 0;
}
//quick sort
void sort(int lo,int hi){
    if (lo>=hi) return;
    int mid = partition(lo, hi);
    sort(lo,mid-1);
    sort(mid+1,hi);
}

int partition(int lo,int hi){
    int i = lo, j = hi+1;
    int v = a[lo];
    while(1){
        while (less(v,a[++i])) if (i==hi) break;
        while (less(a[--j],v)) if (j==lo) break;
        if (i>=j) break;
        exch(i, j);
    }
    exch(lo, j);
    return j;
}

void exch(int i, int j){
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}