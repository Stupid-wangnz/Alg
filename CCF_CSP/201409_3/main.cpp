#include <iostream>

using namespace std;
int open;

bool HaveStr(string s, string str) {
    if (open)
        return s.find(str.c_str()) != string::npos;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] <= 'Z')
            s[i] += 32;
    }
    for (int i = 0; i < str.size(); i++)
        if (str[i] <= 'Z')
            str[i] += 32;

    return s.find(str.c_str()) != string::npos;
}

int main() {
    string str;
    cin >> str;
    int n;
    cin >> open >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (HaveStr(s, str))
            cout << s << endl;
    }
}
