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
// Bellman Ford's Algorithm solving linear programming problem.
#include <climits>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
using namespace std;
typedef long long LL;
typedef pair<int, LL> P;
vector<P> G[105];
LL d[105];

int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    char s[4];
    int a, b;
    LL x;
    for (int i = 0; i <= n + 1; i++)
      G[i].clear();
    for (int i = 0; i < m; i++) {
      scanf("%d%d%s%lld", &a, &b, s, &x);
      if (s[0] == '<') {
        G[a - 1].push_back(P(a + b, x - 1ll));
      } else {
        G[a + b].push_back(P(a - 1, -x - 1ll));
      }
    }
    for (int i = 0; i <= n; i++)
      G[n + 1].push_back(P(i, 0));
    for (int i = 0; i <= n; i++)
      d[i] = LONG_LONG_MAX;
    d[n + 1] = 0;
    bool ans = true;
    for (int c = 0; c <= n + 1; c++) {
      bool update = false;
      for (int i = 0; i <= n + 1; i++) {
        if (d[i] == LONG_LONG_MAX)
          continue;
        for (P &p : G[i]) {
          if (d[i] + p.second < d[p.first]) {
            d[p.first] = d[i] + p.second;
            update = true;
          }
        }
      }
      if (update && c == n + 1) {
        ans = false;
      } else if (!update) {
        break;
      }
    }
    if (ans)
      puts("All aboard the hype bus choo choo.");
    else
      puts("There is no bus in Gensokyo.");
  }
  return 0;
}
