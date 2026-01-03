#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;

    unordered_map<string, int> m;

    int res = 0;
    for (int i = 1; i <= S.length(); i++) {
        for (int j = 0; j <= S.length() - i; j++) {
            string tmp = S.substr(j, i);
            if (m.find(tmp) == m.end()) {
                m.insert({ tmp, 1 });
                res++;
            }
        }
    }
    cout << res;
}