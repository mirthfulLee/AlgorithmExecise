//
// Created by 木子又欠 on 2020/8/22.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long less(long long m,long long n);
void sort(long long a[],long long lo,long long hi);
long long partition(long long a[],long long lo,long long hi);
void exch(long long a[],long long i,long long j);

long long total(long long a[], long long N, long long height) {
    long long get = 0;
    for (int i = 0; i < N; i++) {
        if (a[i]<height){
            break;
        }else{
            get +=a[i] - height;
        }
    }
    return get;
}


int main(){
    long long N, M;
    scanf("%d %d", &N, &M);
    long long a[N];
    for (int i = 0; i < N; i++) {
        scanf("%lld",&a[i]);
    }
    sort(a, 0, N - 1);
    long long lo = 0, hi = a[0], mid, get;
//    一种二分法
//    while (lo < hi) {
//        mid = (lo + hi + 1) / 2;  //为什么要+1
//        get = total(a, N, mid);
//        if (get > M) {
//            lo = mid;
//        } else if (get < M) {
//            hi = mid - 1;  //为什么要-1
//        }else{
//            printf("%lld", mid);
//            return 0;
//        }
//    }
//    printf("%lld", lo);
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        get = total(a, N, mid);
        if (get > M) {
            lo = mid + 1;
        } else if (get < M) {
            hi = mid - 1;  //为什么要-1
        }else{
            printf("%lld", mid);
            return 0;
        }
    }
    printf("%lld", hi);
    //为什么是hi？
    // 假设最后lo==hi，发生偏移使lo>hi,看哪个符合题目要求
    return 0;
}

long long less(long long m,long long n){
    if (m<n){
        return 1;
    }else return 0;
}
//quick sort
void sort(long long a[], long long lo,long long hi){
    if (lo>=hi) return;
    long long mid = partition(a, lo, hi);
    sort(a, lo,mid-1);
    sort(a,mid+1,hi);
}

long long partition(long long a[], long long lo,long long hi){
    long long i = lo, j = hi+1;
    long long v = a[lo];
    while(1){
        while (less(v,a[++i])) if (i==hi) break;
        while (less(a[--j],v)) if (j==lo) break;
        if (i>=j) break;
        exch(a, i, j);
    }
    exch(a, lo, j);
    return j;
}

void exch(long long a[], long long i, long long j){
    long long tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}