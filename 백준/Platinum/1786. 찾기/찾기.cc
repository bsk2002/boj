#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string T, P;

    getline(cin, T);
    getline(cin, P);

    int f[1000001] = { 0 };
    int len = P.length();

    for (int i = 1, j = 0; i < len; i++) {
        while (j > 0 && P[i] != P[j]) j = f[j - 1];
        if (P[i] == P[j]) f[i] = ++j;
    }

    vector<int> idx;
    for (int i = 0, j = 0; i < T.length(); i++) {
        while (j > 0 && T[i] != P[j]) j = f[j - 1];
        if (T[i] == P[j]) j++;
        if (j == len) {
            idx.push_back(i - len + 2);
            j = f[j - 1];
        }
    }
    cout << idx.size() << "\n";
    for (int a : idx) cout << a << " ";
}