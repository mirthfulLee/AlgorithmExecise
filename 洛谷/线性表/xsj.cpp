#include <iostream>
#include <string.h>
using namespace std;
int Left[200010], Right[200010], flag[200010];
int main()
{
    ios::sync_with_stdio(false);
    //mark为零正序，为1倒序。可用mark标记翻转，若为倒序，则插入时左右相反
    //lr判断插入时左右
    //order为每一步指令
    int mark = 0, i, lr, a, b, n, m, k, l, order;
    //初始化
    memset(Left, 0, 200010 * sizeof(int));
    memset(Right, 0, 200010 * sizeof(int));
    memset(flag, 0, 200010 * sizeof(int));

    cin >> n >> m >> k >> l;
    int sum = n + m + k + l;

    for (int i = 0; i < sum; i++)
    {
        cin >> order;

        //插入
        if (order == 1)
        {
            cin >> a >> b >> lr;
            flag[a] = 1;
            if (b != -1)
            {
                //正序
                if (!mark)
                {
                    //正序，则在左边插入就是在左边插入，在b左边插入a
                    if (!lr)
                    {
                        int bl = Left[b];
                        Right[a] = b;
                        Left[a] = Left[b];

                        Left[b] = a;
                        if (bl) Right[bl] = a;
                    }
                        //正序，则在右边插入就是在右边插入，在b右边插入a
                    else
                    {
                        int br = Right[b];
                        Left[a] = b;
                        Right[a] = Right[b];

                        Right[b] = a;
                        if (br) Left[br] = a;
                    }
                }
                    //倒序
                else
                {
                    //倒序，在左边插入即在操作时右边插入，在b右边插入a
                    if (!lr)
                    {
                        int br = Right[b];
                        Left[a] = b;
                        Right[a] = Right[b];

                        Right[b] = a;
                        if (br) Left[br] = a;
                    }
                        //倒序，在右边插入即在操作时左边插入，在b左边插入a
                    else
                    {
                        int bl = Left[b];
                        Right[a] = b;
                        Left[a] = bl;

                        Left[b] = a;
                        if (bl) Right[bl] = a;
                    }
                }
            }
            continue;
        }
        if (order == 0)
        {
            cin >> a;
            //记录要删除的a左右位置
            int ll = Left[a];
            int rr = Right[a];
            Left[a] = 0;
            Right[a] = 0;
            flag[a] = 0;

            if (rr) Left[rr] = ll;
            if (ll) Right[ll] = rr;

            continue;
        }
        if (order == -1)
        {
            cin >> a >> b;

            //a与b不相邻
            if (Left[a] != b && Right[a] != b)
            {
                int al = Left[a], ar = Right[a], bl = Left[b], br = Right[b];
                Left[a] = bl;
                Right[a] = br;
                Left[b] = al;
                Right[b] = ar;

                if (al) Right[al] = b;
                if (ar) Left[ar] = b;
                if (bl) Right[bl] = a;
                if (br) Left[br] = a;
            }
                //a与b相邻
            else
            {
                if (Left[a] == b)
                {
                    int ll = Left[b];
                    int rr = Right[a];
                    Right[b] = rr;
                    Left[b] = a;
                    Left[a] = ll;
                    Right[a] = b;
                    if (ll) Right[ll] = a;
                    if (rr) Left[rr] = b;
                }
                else
                {
                    int ll = Left[a];
                    int rr = Right[b];
                    Right[a] = rr;
                    Left[a] = b;
                    Left[b] = ll;
                    Right[b] = a;
                    if (ll) Right[ll] = b;
                    if (rr) Left[rr] = a;
                }
            }
            continue;
        }
        if (order == -2)
        {
            mark = 1 - mark;
            continue;
        }
    }

    //t为0说明队列中无人
    int t = 0;

    //正序
    if (!mark)
    {
        int min = n + 1;
        //找Left最小的值
        for (i = 1; i <= n; i++)
            if (Left[i] && Left[i] < min) min = Left[i];
        //队列中只有1个或0个
        if (min == n + 1)
        {
            for (i = 1; i <= n; i++)
                if (flag[i])
                {
                    min = i;
                    t = 1;
                    break;
                }
        }
        else t = 1;
        if (!t) min = 0;
        while (min)
        {
            cout << min << ' ';
            min = Right[min];
        }
        cout << "-1";
    }
    else
    {
        int max = 0;
        for (i = 1; i <= n; i++)
            if (Right[i] > max) max = Right[i];
        //队列中只有1个或0个
        if (max == 0)
        {
            for (i = 1; i <= n; i++)
                if (flag[i])
                {
                    max = i;
                    t = 1;
                    break;
                }
        }
        else t = 1;
        if (!t) max = 0;
        while (max)
        {
            cout << max << ' ';
            max = Left[max];
        }
        cout << "-1";
    }
}