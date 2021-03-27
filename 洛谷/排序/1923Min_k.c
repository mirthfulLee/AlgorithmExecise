
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swim(int k);
void sink(int k);
void exch(int i,int j);

int len = 0;
int a[5000000];
//使用降序优先队列(父节点大于等于子节点)
int main(){
    int n,k,tmp;
    scanf("%d %d", &n,&k);
    k++;
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        if (i<k){
            a[++len]=tmp;
            swim(len);
        }else if (tmp<a[1]){
            a[1]=tmp;
            sink(1);
        }
    }
    printf("%d",a[1]);
    return 0;
}
//*********大数上浮*************//
void swim(int k){
    while(k>1 && a[k/2]<a[k]){
        exch(k, k / 2);
        k /= 2;
    }
}
//********小数下沉:与子节点中大的交换*********//
void sink(int k){
    while(2*k<=len){
        int j = 2 * k;
        if (j<len && a[j]<a[j+1]) j++;
        if(a[k]<a[j]){
            exch(k, j);
            k=j;
        }else break;
    }
}
void exch(int i,int j){
    int tmp=a[i];
    a[i] = a[j];
    a[j] = tmp;
}