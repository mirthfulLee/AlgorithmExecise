//
// Created by 木子又欠 on 2020/8/23.
//

#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;


long long n, c;
long long total = 0;
long long count(long long a[],long long target){
    long long count = 0;
    long long lo = 0, hi = n, mid;
    while(lo<=hi){
        mid = (lo + hi) / 2;
        long long v = a[mid];
        if (v < target) {
            lo = mid + 1;
        }else{
            hi = mid -1;
        }
    }
    long long index = lo;
    while (index < n && a[index] == target) {
        count++; index++;
    }
    return count;
}

int main(){

    std::cin >> n >> c;
    long long a[n];
    for (long long i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a, a + n);
    for (long long i = 0; i < n; i++) {
        long long target = a[i] + c;
        long long  tmp = count(a, target);
        long long sum = tmp;
        while (i < n && a[i + 1] == a[i]) {
            i++;
            sum += tmp;
        }
        total += sum;
    }
    cout << total << endl;
    return 0;
}

