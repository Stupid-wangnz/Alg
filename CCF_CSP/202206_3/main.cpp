#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Role {
public:
    //string name;
    bool _op = false, _sc = false;
    vector<string> op_list;
    vector<string> source_class;
    vector<string> source_name;

    bool checkAct(string &op, string &sc, string &sn) {
        string t = "*";
        if (!_op && find(op_list.begin(), op_list.end(), t) == op_list.end() &&
            find(op_list.begin(), op_list.end(), op) == op_list.end())
            return false;
        if (!_sc && find(source_class.begin(), source_class.end(), sc) == source_class.end() &&
            find(source_class.begin(), source_class.end(), t) == source_class.end())
            return false;
        if (!source_name.empty() && find(source_name.begin(), source_name.end(), sn) == source_name.end())
            return false;
        return true;
    }
};

class RoleRef {
public:
    string role_name;
    vector<string> ref_role_list;
/*    bool haveUser(string &user) {
        for (string rr_name: ref_role_list) {
            if (rr_name[0] == 'u' && strcmp(user.c_str(), rr_name.substr(1, rr_name.size() - 1).c_str()) == 0)
                return true;
        }
        return false;
    }

    bool haveGroup(vector<string> &gl) {
        for (const string &gn: gl) {
            for (string rr_name: ref_role_list) {
                if (rr_name[0] == 'g' && strcmp(gn.c_str(), rr_name.substr(1, rr_name.size() - 1).c_str()) == 0)
                    return true;
            }
        }
        return false;
    }*/
};

map<string, Role> Role_list;
//vector<RoleRef> RR_list;

map<string, vector<string>> user_map;

class Act {
public:
    string name;
    vector<string> group_list;
    string op, sc, sn;

    bool check() {
        /*vector<string> roles;
        for (RoleRef rr: RR_list) {
            if (rr.haveUser(this->name)) {
                if (find(roles.begin(), roles.end(), rr.role_name) == roles.end())
                    roles.push_back(rr.role_name);
            } else if (rr.haveGroup(this->group_list))
                if (find(roles.begin(), roles.end(), rr.role_name) == roles.end())
                    roles.push_back(rr.role_name);
        }*/

        /*for (Role r: Role_list) {
            if(find(roles.begin(),roles.end(),r.name) != roles.end())
                if (r.checkAct(this->op, this->sc, this->sn))
                    return true;
        }*/
        string tempname = "u", tempgroup = "g";
        tempname += name;
        vector<string> names = user_map[tempname];
        for (const string &s: names) {
            if (Role_list[s].checkAct(this->op, this->sc, this->sn))
                return true;
        }
        for (const string &s: group_list) {
            tempgroup = "g";
            tempgroup += s;
            names = user_map[tempgroup];
            for (const string &ss: names) {
                if (Role_list[ss].checkAct(this->op, this->sc, this->sn))
                    return true;
            }
        }
        /*for (const string &r: roles) {
            if (Role_list[r].checkAct(this->op, this->sc, this->sn))
                return true;
        }*/
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++) {
        string name;
        Role newRole;
        cin >> name;
        int nv, no, nn;
        cin >> nv;
        string t;
        for (int j = 0; j < nv; j++) {
            cin >> t;
            if (t == "*")
                newRole._op = true;
            newRole.op_list.push_back(t);
        }
        cin >> no;
        for (int j = 0; j < no; j++) {
            cin >> t;
            if (t == "*")
                newRole._sc = true;
            newRole.source_class.push_back(t);
        }
        cin >> nn;
        for (int j = 0; j < nn; j++) {
            cin >> t;
            newRole.source_name.push_back(t);
        }

        Role_list[name] = newRole;
    }

    for (int i = 0; i < m; i++) {
        //RoleRef rr;
        string name;
        cin >> name;
        //cin >> rr.role_name;
        int ns;
        cin >> ns;
        string t1, t2;
        for (int j = 0; j < ns; j++) {
            cin >> t1 >> t2;
            string ref = t1 + t2;
            //rr.ref_role_list.push_back(ref);
            user_map[ref].push_back(name);
        }
        //RR_list.push_back(rr);
    }
    vector<int> res;
    for (int i = 0; i < q; i++) {
        string tg;
        Act act;
        cin >> act.name;
        int ng;
        cin >> ng;
        for (int j = 0; j < ng; j++) {
            cin >> tg;
            act.group_list.push_back(tg);
        }
        cin >> act.op >> act.sc >> act.sn;

        if (act.check())
            res.push_back(1);
        else
            res.push_back(0);
    }

    for (int i: res)
        cout << i << endl;

}
