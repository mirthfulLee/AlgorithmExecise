
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int less(char* a,char* b);
void sort(int lo,int hi);
int partition(int lo,int hi);
void exch(int i,int j);
char a[20][10];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s",a[i]);
    }
    sort(0, n-1);
    for (int i = 0; i < n; i++) {
        printf("%s", a[i]);
    }
    return 0;
}


int less(char* m,char* n){

    int i=0;
    char p=m[i],q=n[i];
    while (p != '\0' && q != '\0') {
        if (p>q) {
            return 0;
        }else if (p<q){
            return 1;
        }else{
            i++;
            p = m[i];
            q = n[i];
        }
    }
    if (p == '\0' && q == '\0') {
        //m==n
        return 1;
    }else if (p=='\0'){
        //m短
        return less(m,n+i);
    }else {
        //n短
        return less(m+i,n);
    }

}
//quick sort
void sort(int lo,int hi){
    if (lo>=hi) return;
    int mid = partition(lo, hi);
    sort(lo,mid);
    sort(mid+1,hi);
}

int partition(int lo,int hi){
    int i = lo, j = hi+1;
    char* v = a[lo];
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
    char tmp[10];
    strcpy(tmp,a[i]);
    strcpy(a[i],a[j]);
    strcpy(a[j],tmp);
}