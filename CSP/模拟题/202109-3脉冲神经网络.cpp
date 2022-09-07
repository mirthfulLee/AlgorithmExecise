// 	202109-3 	脉冲神经网络
// FIXME: 只过了66%，剩余点超时
#include <iostream>
#include <vector>
#include <map>
using namespace std;

static unsigned long nextL = 1;

/* RAND_MAX assumed to be 32767 */
int myrand(void)
{
    nextL = nextL * 1103515245 + 12345;
    return ((unsigned)(nextL / 65536) % 32768);
}
struct synapse
{
    int target, delay;
    double w;
};

struct neure
{
    int cnt;
    double v, u, a, b, c, d;
    vector<double> in;
    vector<synapse> syns;
};
struct source
{
    unsigned long r;
    vector<synapse> syns;
};

int neuralNum, sourceNum, synapseNum, totalTime, totalK;
double deltaT;
vector<neure> neureList;
vector<source> sourceList;
void activateNeure(neure &neu, int t, double delta)
{
    double p = neu.v, q = neu.u;
    neu.v = p + delta * (0.04 * p * p + 5 * p + 140 - q) + neu.in[t];
    neu.u = q + delta * neu.a * (neu.b * p - q);
    if (neu.v >= 30)
    {
        neu.cnt++;
        for (synapse s : neu.syns)
            neureList[s.target].in[t + s.delay] += s.w;

        neu.v = neu.c;
        neu.u = neu.u + neu.d;
    }
}
void activateSource(source &cur, unsigned long threshold, int t)
{
    if (cur.r > threshold)
    {
        for (synapse s : cur.syns)
            neureList[s.target].in[t + s.delay] += s.w;
    }
}

int main()
{
    cin >> neuralNum >> synapseNum >> sourceNum >> totalTime;
    cin >> deltaT;
    totalK = totalTime;
    neureList.resize(neuralNum);
    sourceList.resize(sourceNum);
    int cnt = 0, rn;
    while (cnt < neuralNum)
    {
        neure cur;
        cur.cnt = 0;
        cin >> rn >> cur.v >> cur.u >> cur.a >> cur.b >> cur.c >> cur.d;
        while (rn)
        {
            neureList[cnt] = cur;
            cnt++;
            rn--;
        }
    }

    for (int i = 0; i < neuralNum; i++)
        neureList[i].in.resize(totalK + 1010);

    for (int i = 0; i < sourceNum; i++)
    {
        cin >> sourceList[i].r;
    }
    for (int i = 0; i < synapseNum; i++)
    {
        int p;
        synapse syn;
        cin >> p >> syn.target >> syn.w >> syn.delay;
        if (p >= neuralNum)
            sourceList[p - neuralNum].syns.push_back(syn);
        else
            neureList[p].syns.push_back(syn);
    }
    for (int t = 0; t < totalK; t++)
    {
        for (int i = 0; i < sourceNum; i++)
        {
            unsigned long threshold = myrand();
            activateSource(sourceList[i], threshold, t);
        }
        for (int i = 0; i < neuralNum; i++)
            activateNeure(neureList[i], t, deltaT);
    }
    int minCnt = 9999999, maxCnt = 0;
    double minV = 99999999, maxV = -99999999;
    for (int i = 0; i < neuralNum; i++)
    {
        if (minCnt > neureList[i].cnt)
            minCnt = neureList[i].cnt;
        if (maxCnt < neureList[i].cnt)
            maxCnt = neureList[i].cnt;
        if (minV > neureList[i].v)
            minV = neureList[i].v;
        if (maxV < neureList[i].v)
            maxV = neureList[i].v;
    }
    printf("%.3f %.3f\n%d %d", minV, maxV, minCnt, maxCnt);
}