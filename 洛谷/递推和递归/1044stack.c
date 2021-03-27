//
// Created by 木子又欠 on 2020/7/9.
//

#include <stdio.h>

int main(){
    int a[19][19];
    int n;
    scanf("%d",&n);
    for (int i = 0; i <= n; i++) {
        a[i][0]=1;
    }
    for (int j=1;j<=n;j++){
        a[0][j] = a[1][j - 1];
        for (int i=1;i<=n;i++){
            a[i][j]=a[i+1][j-1]+a[i-1][j];
        }
    }
    printf("%d", a[0][n]);
}


