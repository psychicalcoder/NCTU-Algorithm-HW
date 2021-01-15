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
using namespace std;
typedef long long LL;

struct bird {
  LL x, y, t;
  int r;
  bird() {
    x = y = t = 0ll;
    r = 0;
  }
  bird(LL x, LL y, LL t, int r) : x(x), y(y), t(t), r(r) {}
} a[1005];

bool cmp(const bird &b1, const bird &b2) { return b1.t < b2.t; }

int dp[1005];

inline LL dist(int i, int j) {
  return (a[i].x - a[j].x) * (a[i].x - a[j].x) +
         (a[i].y - a[j].y) * (a[i].y - a[j].y);
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
      scanf("%lld%lld%lld%d", &a[i].x, &a[i].y, &a[i].t, &a[i].r);
    }
    sort(a, a + n, cmp);
    int ans = dp[0] = a[0].r;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if ((a[i].t - a[j].t) * (a[i].t - a[j].t) >= dist(i, j)) {
          if (dp[j] > dp[i])
            dp[i] = dp[j];
        }
      }
      dp[i] += a[i].r;
      if (dp[i] > ans)
        ans = dp[i];
    }
    printf("%d\n", ans);
  }
  return 0;
}
