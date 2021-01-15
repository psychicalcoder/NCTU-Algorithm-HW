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
using namespace std;
typedef long long LL;
typedef pair<int, int> P;

P a[100005];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      scanf("%d%d", &a[i].second, &a[i].first);
    sort(a, a+n);
    int cur = a[0].first;
    int ans = 1;
    for (int i = 1; i < n; i++) {
      if (a[i].second >= cur) {
        ans++;
        cur = a[i].first;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
