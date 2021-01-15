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

int V, E;

struct edge {
  int from, to, cost;
};

int dis[1005];
vector<edge> pool;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &V, &E);
    int u, v, c;
    for (int i = 0; i < V; i++) {
      dis[i] = 1000000;
    }
    pool.clear();
    for (int i = 0; i < E; i++) {
      scanf("%d%d%d", &u, &v, &c);
      pool.push_back((edge){u, v, c});
    }
    int epoch = 0;
    bool ok = false;
    while (epoch < V) {
      bool update = false;
      for (edge &ee : pool) {
        if (dis[ee.to] > dis[ee.from] + ee.cost) {
          dis[ee.to] = dis[ee.from] + ee.cost;
          update = true;
        }
      }
      if (!update) {
        ok = true;
        break;
      }
      epoch++;
    }
    puts(ok ? "El Psy Kongroo" : "This is the choice of Steins;Gate");
  }
  return 0;
}
