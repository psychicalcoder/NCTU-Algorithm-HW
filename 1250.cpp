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
#include <utility>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair<int,int> P;

P a[10005];

bool cmp(const P& p1, const P& p2) {
  return p1.second - p1.first > p2.second - p2.first;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
      scanf("%d%d", &a[i].first, &a[i].second);
    }
    sort(a, a+N, cmp);
    LL ans = 0;
    for (int i = 0; i < (N>>1); i++) {
      ans += a[i].first;
      ans += a[i+(N>>1)].second;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
