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
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;

vector<int> G[10005];

int low[10005], vis[10005];
int stamp, cnt;
int stk[10005], instk[10005];
int tp;
int color[10005];
int deg[10005];

void tarjan(int x) {
  low[x] = vis[x] = ++stamp;
  stk[tp++] = x;
  instk[x] = 1;
  for (int i = 0, y; i < G[x].size(); i++) {
    if (!vis[y = G[x][i]])
      tarjan(y);
    if (instk[y])
      low[x] = min(low[x], low[y]);
  }
  if (vis[x] == low[x]) {
    int u;
    do {
      instk[u = stk[--tp]] = 0;
      color[u] = cnt;
    } while (u != x);
    cnt++;
  }
}

int main() {
  int N, E, V;
  scanf("%d", &N);
  while (N--) {
    int u, v;
    scanf("%d%d", &E, &V);
    for (int i = 1; i <= E; i++)
      G[i].clear();
    for (int i = 1; i <= V; i++) {
      scanf("%d%d", &u, &v);
      G[u].push_back(v);
    }
    memset(instk, 0, sizeof(instk));
    memset(vis, 0, sizeof(vis));
    memset(stk, 0, sizeof(stk));
    memset(deg, 0, sizeof(deg));
    tp = 0;
    stamp = 0;
    cnt = 0;
    for (int i = 1; i <= E; i++) {
      if (!vis[i])
        tarjan(i);
    }
    for (int i = 1; i <= E; i++) {
      // printf(" node %d belongs to SCC %d\n", i, color[i]);
      for (int j = 0; j < G[i].size(); j++) {
        v = G[i][j];
        if (color[i] != color[v]) {
          deg[color[v]]++;
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < cnt; i++) {
      if (deg[i] == 0)
        ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}
