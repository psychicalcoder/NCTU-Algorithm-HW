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
#include <map>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;

P a1[100005];
map<int, int> mp;

bool cmp(const P &a, const P &b) {
  if (a.first == -1 && b.first == -1)
    return a.second < b.second;
  else if (a.first == -1)
    return false;
  else if (b.first == -1)
    return true;
  else
    return a.first < b.first;
}

int main() {
  int T, m, n, x;
  scanf("%d", &T);
  while (T--) {
    mp.clear();
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i++) {
      scanf("%d", &(a1[i].second));
    }
    for (int i = 0; i < n; i++) {
      scanf("%d", &x);
      mp[x] = i;
    }
    for (int i = 0; i < m; i++) {
      if (mp.count(a1[i].second))
        a1[i].first = mp[a1[i].second];
      else
        a1[i].first = -1;
    }
    sort(a1, a1 + m, cmp);
    printf("%d", a1[0].second);
    for (int i = 1; i < m; i++)
      printf(" %d", a1[i].second);
    putchar('\n');
  }
}
