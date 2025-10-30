#include <bits/stdc++.h>
using namespace std;

int H, N;
int arr[500002];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> H;

    int x;
    for (int i = 1; i <= N; i++) {
        cin >> x;

        if (i % 2 == 1) {
            arr[1]++;
            arr[x + 1]--;
        }
        else {
            arr[H + 1]--;
            arr[H - x + 1]++;
        }
    }

    int res = __INT_MAX__;
    for (int i = 1; i <= H; i++) {
        arr[i] = arr[i] + arr[i - 1];
        res = min(res, arr[i]);
    }

    int cnt = 0;
    for (int i = 1; i <= H; i++) {
        if (arr[i] == res) cnt++;
    }

    cout << res << " " << cnt;
}