#include <bits/stdc++.h>
using namespace std;

char board[3100][6200];

void solve(int n, int y, int x) {
    if (n == 3) {
        board[y][x] = '*';
        board[y + 1][x - 1] = '*'; board[y + 1][x + 1] = '*';
        board[y + 2][x - 2] = '*'; board[y + 2][x - 1] = '*';
        board[y + 2][x] = '*';     board[y + 2][x + 1] = '*'; board[y + 2][x + 2] = '*';
        return;
    }

    int ns = n / 2; // 다음 단계의 크기
    solve(ns, y, x); // 위쪽 삼각형
    solve(ns, y + ns, x - ns); // 왼쪽 아래 삼각형
    solve(ns, y + ns, x + ns); // 오른쪽 아래 삼각형
}

int main() {
    int N;
    cin >> N;

    memset(board, ' ', sizeof(board));

    solve(N, 0, N - 1);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2 * N - 1; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }

    return 0;
}