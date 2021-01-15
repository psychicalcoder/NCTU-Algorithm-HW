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
vector<edge> ans;

int a[105];

void init() {
  for (int i = 0; i < 105; i++) {
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
    pool.clear();
    ans.clear();
    scanf("%d%d", &V, &E);
    int u, v, c;
    for (int i = 0; i < E; i++) {
      scanf("%d%d%d", &u, &v, &c);
      if (u == v)
        continue;
      pool.push_back(edge(u, v, c));
    }
    E = pool.size();
    sort(pool.begin(), pool.end(),
         [](const edge &ee1, const edge &ee2) { return ee1.cost < ee2.cost; });
    int eqn = pool.back().cost - pool.front().cost;
    bool ok = false;
    for (int i = 0; i < E; i++) {
      init();
      int mn = pool[i].cost;
      int mx;
      for (int j = i; j < E; j++) {
        edge &ee = pool[j];
        if (!same(ee.from, ee.to)) {
          unite(ee.from, ee.to);
          mx = ee.cost;
        }
      }
      bool conn = true;
      for (int j = 2; j <= V; j++) {
        if (!same(j, j - 1)) {
          conn = false;
          break;
        }
      }
      if (conn) {
        if (eqn > mx - mn) {
          eqn = mx - mn;
        }
        ok = true;
      } else {
        break;
      }
    }
    if (ok) {
      printf("%d\n", eqn);
    } else
      puts("-1");
  }
  return 0;
}
