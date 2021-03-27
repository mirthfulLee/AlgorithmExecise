//
// Created by 木子又欠 on 2020/9/29.
//

#include <iostream>
using namespace std;

int a[200010], b[200010];
//同学i 左边是a[i],右边是b[i]
int main(){
    int n, m, k, l, i, j, way, tmp, t, p, q, r, s;
    cin >> n >> m >> k >> l;
    t = 0;
    a[0]=n+1;
    b[n+1]=0;
    for (int tmpi = 0; tmpi<n+m+k+l;tmpi++){
        cin >> tmp;
        switch(tmp){
            case 1:
                //入队
                cin >> i >> j >> way;
                if (j == -1){
                    a[i] = 0;
                    b[0] = i;
                    b[i] = n + 1;
                    a[n + 1] = i;
                }else if (!((way + t) % 2)){
                    //i 在 j 左侧
                    b[a[j]] = i;
                    a[i] = a[j];
                    b[i] = j;
                    a[j] = i;
                }else{
                    //i 在 j 右侧
                    a[b[j]]= i;
                    b[i] = b[j];
                    a[i] = j;
                    b[j] = i;
                }

                break;
            case 0:
                //出队
                cin >> i;
                b[a[i]] = b[i];
                a[b[i]] = a[i];
                break;
            case -1:
                //交换位置
                cin >> i >> j;
                if (i == a[j]){
                    //i 在 j 左侧
                    p = a[i]; q = b[j];
                    b[p] = j; a[j] = p;
                    a[q] = i; b[i] = q;
                    b[j] = i; a[i] = j;
                }else if (i == b[j]){
                    //i 在 j 右侧
                    p = a[j]; q = b[i];
                    b[p] = i; a[i] = p;
                    a[q] = j; b[j] = q;
                    a[j] = i; b[i] = j;
                }else{
                    p = a[i]; q = b[i];
                    r = a[j]; s = b[j];
                    a[s] = i; b[r] = i;
                    a[q] = j; b[p] = j;
                    a[i] = r; b[i] = s;
                    a[j] = p; b[j] = q;
                }

                break;
            case -2:
                //翻转
                t++;
                break;
        }
    }
    //输出
    if (l % 2){
        //从右往左
        i = a[n+1];
        while (i){
            cout << i << " ";
            i = a[i];
        }
    }else{
        //从左往右
        i = b[0];
        while(i != n+1){
            cout << i << " ";
            i = b[i];
        }
    }
    cout << -1 << endl;
}