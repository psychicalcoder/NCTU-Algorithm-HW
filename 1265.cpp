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

// Dinic's ALgorithm
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
typedef long long LL;

struct Edge {
  int from, to, cap, flow;
  Edge() : from(0), to(0), cap(0), flow(0) {}
  Edge(int from, int to, int cap, int flow)
      : from(from), to(to), cap(cap), flow(flow) {}
};

vector<Edge> edges;
vector<int> G[205];
int level[205];
bool vis[205], cur[205];

int n, k, r;
int s, t;

bool bfs() {
  memset(level, 0, sizeof(level));
  memset(vis, false, sizeof(vis));
  queue<int> q;
  level[s] = 0;
  vis[s] = true;
  q.push(s);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int ei : G[x]) {
      Edge &e = edges[ei];
      if ((!vis[e.to]) && e.cap > e.flow) {
        level[e.to] = level[e.from] + 1;
        vis[e.to] = true;
        q.push(e.to);
      }
    }
  }
  return vis[t];
}

int dfs(int x, int flw) {
  if (x == t || flw == 0)
    return flw;
  int ans = 0;
  for (int i = cur[x]; i < G[x].size(); i++) {
    Edge &e = edges[G[x][i]];
    if (level[x] + 1 == level[e.to]) {
      int f = dfs(e.to, min(flw, e.cap - e.flow));
      if (f > 0) {
        e.flow += f;
        edges[G[x][i] ^ 1].flow -= f;
        ans += f;
        flw -= f;
        if (flw == 0)
          break;
      }
    }
  }
  return ans;
}

void addedge(int from, int to, int cap) {
  edges.push_back(Edge(from, to, cap, 0));
  edges.push_back(Edge(to, from, 0, 0));
  int m = edges.size();
  G[from].push_back(m - 2);
  G[to].push_back(m - 1);
}

int main() {
  int T, tmp;
  scanf("%d", &T);
  while (T--) {
    edges.clear();
    scanf("%d%d%d", &n, &r, &k);
    for (int i = 0; i <= n + r + 1; i++)
      G[i].clear();
    s = n + r, t = n + r + 1;
    for (int i = 0; i < n; i++) {
      addedge(s, i, 1);
    }
    for (int i = 0; i < r; i++) {
      addedge(i + n, t, 1);
    }
    int u, v;

    for (int i = 0; i < k; i++) {
      scanf("%d%d", &u, &v);
      addedge(u, v + n, 100000000);
    }

    int ans = 0;
    while (bfs()) {
      memset(cur, 0, sizeof(cur));
      ans += dfs(s, 100000000);
    }
    printf("%d\n", ans);
  }
  return 0;
}
