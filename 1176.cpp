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
#include <cstdio>
using namespace std;
typedef long long LL;

int G[10][10];
int row[10][10];
int col[10][10];
int s[10][10];
int left;

void draw() {
  for (int i = 0; i < 9; i++) {
    printf("%d", G[i][0]);
    for (int j = 1; j < 9; j++) {
      printf(" %d", G[i][j]);
    }
    putchar('\n');
  }
  getchar();
}

bool dfs(int r, int c) {
  if (left == 0)
    return true;
  // printf("call r = %d c = %d %d\n", r, c, left);
  for (int i = r; i < 9; i++) {
    int j;
    if (i == r)
      j = c;
    else
      j = 0;
    for (; j < 9; j++) {
      if (G[i][j] == 0) {
        for (int k = 1; k < 10; k++) {
          if (!row[i][k] && !col[j][k] && !s[i / 3 * 3 + j / 3][k]) {
            row[i][k] = 1;
            col[j][k] = 1;
            s[i / 3 * 3 + j / 3][k] = 1;
            G[i][j] = k;
            left--;
            // printf("fill %d %d with %d\n", i, j, k);
            // draw();
            if (left == 0)
              return true;
            if (dfs(i, j))
              return true;
            row[i][k] = 0;
            col[j][k] = 0;
            s[i / 3 * 3 + j / 3][k] = 0;
            G[i][j] = 0;
            left++;
          }
        }
        return false;
      }
    }
  }
  return false;
}

int main() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      scanf("%d", &G[i][j]);
      if (G[i][j] == 0)
        left++;
      else {
        row[i][G[i][j]]++;
        col[j][G[i][j]]++;
        s[i / 3 * 3 + j / 3][G[i][j]]++;
      }
    }
  }

  bool ok = true;
  for (int i = 0; i < 9; i++) {
    for (int j = 1; j <= 9; j++) {
      if (row[i][j] > 1 || col[i][j] > 1 || s[i][j] > 1) {
        ok = false;
        break;
      }
    }
    if (!ok)
      break;
  }

  // printf("%d\n", left);
  if (ok && dfs(0, 0)) {
    for (int i = 0; i < 9; i++) {
      printf("%d", G[i][0]);
      for (int j = 1; j < 9; j++) {
        printf(" %d", G[i][j]);
      }
      putchar('\n');
    }
  } else {
    puts("NO");
  }

  return 0;
}
