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
#include <queue>
#include <utility>
#include <vector>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;

int V, E, start, finish;

struct edge {
  int to, cost;
};

int dis[20005];
int vis[20005];
vector<int> G[20005];
vector<edge> pool;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d%d", &V, &E, &start, &finish);
    int u, v, c;
    for (int i = 0; i < V; i++) {
      dis[i] = 2147483647;
      vis[i] = 0;
      G[i].clear();
    }
    pool.clear();
    for (int i = 0; i < E; i++) {
      scanf("%d%d%d", &u, &v, &c);
      if (u == v)
        continue;
      pool.push_back((edge){v, c});
      pool.push_back((edge){u, c});
      G[u].push_back(pool.size() - 2);
      G[v].push_back(pool.size() - 1);
    }
    dis[start] = 0;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push(P(dis[start], start));
    while (!pq.empty()) {
      if (vis[pq.top().second]) {
        pq.pop();
        continue;
      }
      u = pq.top().second;
      pq.pop();
      for (int i : G[u]) {
        edge &ee = pool[i];
        v = ee.to;
        if (dis[v] > dis[u] + ee.cost) {
          dis[v] = dis[u] + ee.cost;
          pq.push(P(dis[v], v));
        }
      }
      vis[u] = 1;
    }
    if (dis[finish] < 2147483647) {
      printf("%d\n", dis[finish]);
    } else {
      printf("YOU DIED\n");
    }
  }
  return 0;
}
