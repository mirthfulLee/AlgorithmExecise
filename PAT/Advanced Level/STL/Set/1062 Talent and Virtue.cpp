// 1062 Talent and Virtue
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

struct person
{
    // type: sage-3; noble-2; fool-1;
    int id, virtue, talent, total, type;
    bool operator<(const person &b) const
    {
        if (type == b.type)
        {
            if (total == b.total)
            {
                if (virtue == b.virtue)
                    return id < b.id;
                else
                    return virtue > b.virtue;
            }
            else
                return total > b.total;
        }
        else
            return type > b.type;
    }
};
int main(){
    int n, l, h;
    person cur;
    set<person> people;
    cin >> n >> l >> h;
    for (int i = 0; i < n;i++){
        cin >> cur.id >> cur.virtue >> cur.talent;
        if (cur.talent<l || cur.virtue <l) continue;
        cur.total = cur.virtue + cur.talent;
        if (cur.virtue>=h)
            cur.type = cur.talent >= h ? 3 : 2;
        else
            cur.type = cur.virtue >= cur.talent ? 1 : 0;
        people.insert(cur);
    }
    printf("%d\n", people.size());
    for (person p: people){
        printf("%d %d %d\n", p.id, p.virtue, p.talent);
    }
}
