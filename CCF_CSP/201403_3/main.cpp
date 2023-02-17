#include <iostream>
#include <sstream>

using namespace std;

int idx(char c) {
    return c - 'a';
}

int opt[26]{};

int main() {
    char format[52];
    cin >> format;
    int x = 0;
    while (format[x]) {
        opt[idx(format[x])]++;
        if (format[x + 1] == ':') {
            opt[idx(format[x])]++;
            x++;
        }
        x++;
    }

    int N;
    cin >> N;
    cin.get();
    for (int i = 0; i < N; i++) {
        char orders[256];
        cin.getline(orders, 256);
        stringstream ss(orders);
        string order_name;
        string order_opt;
        ss >> order_name;
        string opt_record[26]{};
        while (ss >> order_opt) {
            if (order_opt[0] != '-')
                break;
            if (opt[idx(order_opt[1])] == 0 || order_opt.length()>2)
                break;
            if (opt[idx(order_opt[1])] == 1) {
                opt_record[idx(order_opt[1])] = "-";
                opt_record[idx(order_opt[1])] += order_opt[1];
            }
            else if (opt[idx(order_opt[1])] == 2) {
                string opt_seg;
                if(ss>>opt_seg){
                    opt_record[idx(order_opt[1])] = "-";
                    opt_record[idx(order_opt[1])] += order_opt[1];
                    opt_record[idx(order_opt[1])] += " ";
                    opt_record[idx(order_opt[1])] += opt_seg;
                }
            }
        }

        cout << "Case " << i + 1 << ": ";
        for (int i = 0; i < 26; i++) {
            if (opt_record[i] == "")
                continue;
            cout << opt_record[i] << " ";
        }
        cout << endl;
    }
}
