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
#include <map>
using namespace std;
typedef long long LL;
typedef pair<int,int> P;

map<P,int> m;

int main() {
  int n;
  while(scanf("%d", &n) != EOF && n) {
    int from, to;
    for (int i = 0; i < n; i++) {
      scanf("%d%d", &from, &to);
      P pp(to, from);
      if (m.count(pp) && m[pp] > 0) {
        m[pp]--;
      }
      else {
        P ff(from, to);
        if (m.count(ff)) {
          m[ff]++;
        } else {
          m[ff] = 1;
        }
      }
    }
    map<P,int>::iterator iter;
    iter = m.begin();
    bool ans = true;
    while (iter != m.end()) {
      if (iter->second > 0) {
        ans = false;
        break;
      }
      iter++;
    }
    printf("%s\n", ans ? "YES" : "NO");
    m.clear();
  }
  return 0;
}
