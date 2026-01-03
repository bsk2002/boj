#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int A, B;
    cin >> A >> B;

    unordered_map<int, int> m;

    int res = 0;
    for (int i = 0; i < A; i++) {
        int x;
        cin >> x;
        if (m.find(x) == m.end()) {
            m.insert({ x, 1 });
        }
        else res++;
    }
    for (int i = 0; i < B; i++) {
        int x;
        cin >> x;
        if (m.find(x) == m.end()) {
            m.insert({ x, 1 });
        }
        else res++;
    }
    cout << A + B - (res * 2);
}