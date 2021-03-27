
//
// Created by 木子又欠 on 2020/7/9.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*Swap function to swap two values*/
void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

/*delete a element of arr ,where its index is t*/
void delete(int* arr,int n, int t){
    for (int i = t; i < n; i++) {
        arr[i]=arr[i+1];
    }
}

int main()
{
    int a[300];
    char c;
    int n=0,k,min,up;
    while (isprint(c=getchar())){
        a[n]=c-'0';
        n++;
    }
    scanf("%d", &k);

    for (int i = 0; i < k; i++) {
        up=n-1;
        for (int j = 0; j < n-1; j++) {
            if (a[j]>a[j+1]){
                up=j;
                break;
            }
        }
        delete(a, n--, up);
    }


    /**没有考虑周全！**/
    while (a[0] == 0 && n > 1) {
        delete(a, n--, 0);
    }

    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
    }

}
