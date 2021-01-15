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
#include <cstring>
using namespace std;
typedef long long LL;

int a[10005];
int b[10005];
int used[10005];
int M, n, s;

int dfs(int from) {
  if (a[from] == 0) {
    b[from] = 1;
    used[from] = 1;
    return 1;
  }
  if (used[from]) {
    return b[from];
  } else {
    used[from] = 1;
    if (from + a[from] < n)
      b[from] |= dfs(from + a[from]);
    if (from - a[from] >= 0)
      b[from] |= dfs(from - a[from]);
    return b[from];
  }
}

int main() {
  scanf("%d", &M);
  while (M--) {
    scanf("%d%d", &n, &s);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    memset(b, 0, sizeof(b));
    memset(used, 0, sizeof(used));
    bool ans = dfs(s);
    if (ans)
      puts("We will watch your career with great interest.");
    else
      puts("My disappointment is immeasurable, and my day is ruined.");
  }
  return 0;
}
