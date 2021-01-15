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
#include <vector>
using namespace std;

vector<int> rG[10005];
int used[10005];
vector<int> ans;
bool flag;

void dfs(int from) {
  used[from] = 1;
  for (int v : rG[from]) {
    if (used[v] == 1) flag = true; 
    if (!used[v])
      dfs(v);
  }
  ans.push_back(from);
  used[from] = 2;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int R, K, N, u, v;
    scanf("%d%d%d", &R, &K, &N);
    for (int i = 0; i < R; i++) {
      rG[i].clear();
    }
    ans.clear();
    memset(used, 0, sizeof(used));
    for (int i = 0; i < K; i++) {
      scanf("%d%d", &u, &v);
      rG[v].push_back(u);
    }
    dfs(N);
    if (flag) puts("Lion can not pass this chapter!");
    else {
      printf("%d", ans[0]);
      for (int i = 1; i < ans.size(); i++) {
        printf(" %d", ans[i]);
      }
      putchar('\n');
    }
  }
  return 0;
}
