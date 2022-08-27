// 	202206-3 角色授权
// FIXME: 只达到了70%， 剩下的点依旧超时
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

struct role
{
    set<string> opts, rs_types, rs_names;
};

map<string, set<string>> user_role_map, group_role_map;

struct query
{
    string name;
    vector<string> groups;
    string opt, rs_type, rs_name;
};

map<string, role> role_map;
// map<string, relation> relation_map;
int n, m, q, a, b, c, flag;
string opt, rs_type, rs_name, user, name, tmp1, tmp2;
vector<string> groups;

bool check(query q)
{
    set<string> related_roles;
    for (string role : user_role_map[q.name])
        related_roles.insert(role);

    for (string g : q.groups)
        for (string role : group_role_map[g])
            related_roles.insert(role);
    for (string role_name : related_roles)
    {
        role curRole = role_map[role_name];
        // check opt
        if (curRole.opts.find("*") == curRole.opts.end() && curRole.opts.find(q.opt) == curRole.opts.end())
            continue;
        // check rs_type
        if (curRole.rs_types.find("*") == curRole.rs_types.end() && curRole.rs_types.find(q.rs_type) == curRole.rs_types.end())
            continue;
        // check rs_name
        if (!curRole.rs_names.empty() && curRole.rs_names.find(q.rs_name) == curRole.rs_names.end())
            continue;
        return true;
    }
    return false;
}

int main()
{
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++)
    {
        role cur;
        cin >> name >> a;
        for (int j = 0; j < a; j++)
        {
            cin >> tmp1;
            cur.opts.insert(tmp1);
        }
        cin >> a;
        for (int j = 0; j < a; j++)
        {
            cin >> tmp1;
            cur.rs_types.insert(tmp1);
        }
        cin >> a;
        for (int j = 0; j < a; j++)
        {
            cin >> tmp1;
            cur.rs_names.insert(tmp1);
        }
        role_map[name] = cur;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> name >> a;
        for (int j = 0; j < a; j++)
        {
            cin >> tmp1 >> tmp2;
            if (tmp1[0] == 'u')
                user_role_map[tmp2].insert(name);
            else
                group_role_map[tmp2].insert(name);
        }
    }
    for (int k = 0; k < q; k++)
    {
        flag = 0;
        query cur;
        cin >> cur.name >> a;
        cur.groups.resize(a);
        for (int i = 0; i < a; i++)
            cin >> cur.groups[i];
        cin >> cur.opt >> cur.rs_type >> cur.rs_name;
        cout << (check(cur) ? 1 : 0) << endl;
    }
}
