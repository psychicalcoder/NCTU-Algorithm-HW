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
#include <cstring>
#include <queue>
using namespace std;
typedef long long LL;

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    int n, m, k, v;
    int count[10];
    int ans = 0;
    queue<int> q;
    memset(count, 0, sizeof(count));
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
      scanf("%d", &k);
      count[k]++;
      if (i == m) {
        q.push(-1);
        v = k;
      }
      else q.push(k);
    }
    while(!q.empty()) {
      int fnt = q.front();
      if (fnt != -1) {
        bool pnt = true;
        for (int i = fnt+1; i <= 9 ; i++)
          if (count[i] >= 1) {
            pnt = false;
            break;
          }
        if (pnt) {
          ans++;
          q.pop();
          count[fnt]--;
        } else {
          q.push(fnt);
          q.pop();
        }
      } else {
        bool pnt = true;
        for (int i = v+1; i <= 9; i++)
          if (count[i] >= 1) {
            pnt = false;
            break;
          }
        if (pnt) {
          ans++;
          break;
        } else {
          q.push(fnt);
          q.pop();
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
