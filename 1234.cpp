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
#include <utility>
#include <vector>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;

int V, E;
struct edge {
  int from, to;
  LL cost;
  edge() {
    from = 0;
    to = 0;
    cost = 0ll;
  }
  edge(int from, int to, int cost) : from(from), to(to), cost(cost) {}
};

vector<edge> pool;
vector<pair<int, int>> g;
vector<edge> ans;

int a[755];

void init() {
  for (int i = 0; i < 755; i++) {
    a[i] = i;
  }
}

int search(int p) {
  if (a[p] == p)
    return p;
  else {
    return (a[p] = search(a[p]));
  }
}

void unite(int p, int q) { a[search(p)] = search(q); }

bool same(int p, int q) { return search(p) == search(q); }

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    init();
    pool.clear();
    g.clear();
    ans.clear();
    scanf("%d", &V);
    int x, y;
    g.push_back(P(0, 0));
    for (int i = 0; i < V; i++) {
      scanf("%d%d", &x, &y);
      g.push_back(P(x, y));
    }
    scanf("%d", &E);
    for (int i = 0; i < E; i++) {
      scanf("%d%d", &x, &y);
      unite(x, y);
    }
    for (int i = 1; i <= V; i++) {
      for (int j = i + 1; j <= V; j++) {
        LL ix = g[i].first;
        LL iy = g[i].second;
        LL jx = g[j].first;
        LL jy = g[j].second;
        pool.push_back(
            edge(i, j, (ix - jx) * (ix - jx) + (iy - jy) * (iy - jy)));
      }
    }
    sort(pool.begin(), pool.end(),
         [](const edge &ee1, const edge &ee2) { return ee1.cost < ee2.cost; });
    for (edge &ee : pool) {
      if (!same(ee.from, ee.to)) {
        unite(ee.from, ee.to);
        ans.push_back(ee);
      }
    }
    printf("%d\n", int(ans.size()));
    for (edge &ee : ans) {
      printf("%d %d\n", ee.from, ee.to);
    }
  }
  return 0;
}
