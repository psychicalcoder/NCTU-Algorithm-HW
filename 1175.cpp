/*
  Copyright (C) 2021 Marvin Liu

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#include <cctype>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;

char readchar() {
  char ch;
  while ((ch = getchar()) != EOF) {
    if (isalpha(ch))
      return ch;
  }
  return EOF;
}

char G[70][70];
int T, M, N;
int ans;
int s[70][70];
/* 0 not used
 * 1 |
 * 2 -
 * 3 _|
 * 4 "|
 * 5 L
 * 6 |"
 * 7 Blank
 * 1 2 3 4 up down left right*/

void dfs(int r, int c, int fdir) {
  if (r < 0 || r >= M || c < 0 || c >= N)
    return;
  if (r == M - 1 && c == N - 1) {
    ans++;
    return;
  } else if (s[r][c])
    return;
  else if (G[r][c] == 'B')
    return;
  else if (G[r][c] == 'L') {
    if (fdir == 1) {
      s[r][c] = 1;
      dfs(r + 1, c, 1);
    } else if (fdir == 2) {
      s[r][c] = 1;
      dfs(r - 1, c, 2);
    } else if (fdir == 3) {
      s[r][c] = 2;
      dfs(r, c + 1, 3);
    } else if (fdir == 4) {
      s[r][c] = 2;
      dfs(r, c - 1, 4);
    }
    s[r][c] = 0;
  } else if (G[r][c] == 'T') {
    if (fdir == 1) {
      s[r][c] = 3;
      dfs(r, c - 1, 4);
      s[r][c] = 5;
      dfs(r, c + 1, 3);
    } else if (fdir == 2) {
      s[r][c] = 4;
      dfs(r, c - 1, 4);
      s[r][c] = 6;
      dfs(r, c + 1, 3);
    } else if (fdir == 3) {
      s[r][c] = 4;
      dfs(r + 1, c, 1);
      s[r][c] = 3;
      dfs(r - 1, c, 2);
    } else if (fdir == 4) {
      s[r][c] = 6;
      dfs(r + 1, c, 1);
      s[r][c] = 5;
      dfs(r - 1, c, 2);
    }
    s[r][c] = 0;
  }
}

int main() {

  scanf("%d", &T);
  while (T--) {
    memset(G, 0, sizeof(G));
    memset(s, 0, sizeof(s));
    ans = 0;
    scanf("%d%d", &M, &N);
    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
        G[i][j] = readchar();
        if (G[i][j] == 'B')
          s[i][j] = 7;
      }
    }
    if (G[0][0] == 'B' || G[M - 1][N - 1] == 'B') {
      puts("Number of legal solutions: 0");
      continue;
    }
    if (M * N == 1) {
      puts("Number of legal solutions: 2");
      continue;
    }
    if (G[0][0] == 'L') {
      s[0][0] = 1;
      dfs(1, 0, 1);
      s[0][0] = 2;
      dfs(0, 1, 3);
    } else if (G[0][0] == 'T') {
      s[0][0] = 4;
      dfs(1, 0, 1);
      s[0][0] = 5;
      dfs(0, 1, 3);
    }
    printf("Number of legal solutions: %d\n", ans);
  }
  return 0;
}
