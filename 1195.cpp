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
#include <queue>
#include <utility>
#include <vector>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;

struct edge {
  int to, val;
  edge(int to, int val) : to(to), val(val) {}
  edge() : to(0), val(0) {}
};

vector<edge> G[100005];
int used[100005];
int dist[100005];
int ans;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int N, K, u, v;
    memset(dist, -1, sizeof(dist));
    memset(used, 0, sizeof(used));
    for (int i = 0; i < N; i++)
      G[i].clear();
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++) {
      scanf("%d%d", &u, &v);
      if (u != -1)
        G[u].push_back(edge(i, v));
      else {
        dist[i] = v;
        ans = v;
      }
    }
    queue<int> q;
    q.push(K);
    while (!q.empty()) {
      u = q.front();
      q.pop();
      // printf("u = %d\n", u);
      for (int i = 0; i < G[u].size(); i++) {
        edge &e = G[u][i];
        // printf("from %d to %d take %d\ndist u = %d\n", u, e.to, e.val,
        // dist[u]);
        q.push(e.to);
        dist[e.to] = dist[u] + e.val;
        if (ans < dist[e.to])
          ans = dist[e.to];
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
