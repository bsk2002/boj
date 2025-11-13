#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<char> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];

    // failure array
    vector<int> f(N, 0);
    for (int i = 1, j = 0; i < N; i++) {
        while (j > 0 && A[i] != A[j]) j = f[j - 1];
        if (A[i] == A[j]) f[i] = ++j;
    }

    // B+B 생성
    vector<char> BB(2 * N);
    for (int i = 0; i < N; i++) BB[i] = BB[i + N] = B[i];

    // KMP 탐색
    int cnt = 0;
    for (int i = 0, j = 0; i < 2 * N; i++) {
        while (j > 0 && BB[i] != A[j]) j = f[j - 1];
        if (BB[i] == A[j]) j++;
        if (j == N) {
            if (i - N + 1 < N) cnt++;
            j = f[j - 1];
        }
    }

    int g = gcd(cnt, N);
    cout << cnt / g << "/" << N / g;
}