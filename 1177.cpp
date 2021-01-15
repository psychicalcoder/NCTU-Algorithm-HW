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
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;

struct pt {
  LL x, y;
} a[10005];

struct P {
  int u, v;
  LL d;
  P() : u(0), v(0), d(0) {}
  P(int u, int v, LL d) : u(u), v(v), d(d) {}
};

vector<P> cand;
bool *del;

bool cmp(const P &a, const P &b) {
  if (a.d == b.d) {
    if (a.u == b.u) {
      return a.v < b.v;
    }
    return a.u < b.u;
  }
  return a.d < b.d;
}

int main() {
  int n;
  scanf("%d", &n);
  int ans = 0;
  for (int i = 0; i < n; i++)
    scanf("%lld%lld", &a[i].x, &a[i].y);
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      LL dist = (a[i].x - a[j].x) * (a[i].x - a[j].x) +
                (a[i].y - a[j].y) * (a[i].y - a[j].y);
      if (dist < 40000ll) {
        cand.push_back(P(i, j, dist));
      }
    }
  }
  sort(cand.begin(), cand.end(), cmp);
  del = new bool[cand.size()];
  memset(del, 0, sizeof(bool) * cand.size());
  for (int i = 0; i < cand.size(); i++) {
    if (!del[i]) {
      ans++;
      int u = cand[i].u;
      int v = cand[i].v;
      int dd = u;
      if ((a[u].x - 20000ll) * (a[u].x - 20000ll) +
              (a[u].y - 20000ll) * (a[u].y - 20000ll) >
          (a[v].x - 20000ll) * (a[v].x - 20000ll) +
              (a[v].y - 20000ll) * (a[v].y - 20000ll)) {
        dd = v;
      }
      // printf("del %d\n", dd);
      for (int j = i + 1; j < cand.size(); j++) {
        if (cand[j].u == dd || cand[j].v == dd) {
          del[j] = true;
        }
      }
    }
  }
  printf("Number of removed 7-11 stores: %d\n", ans);
  return 0;
}
