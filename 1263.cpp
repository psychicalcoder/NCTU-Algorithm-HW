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
using namespace std;
typedef long long LL;

LL d[105][41];

int main() {
  int n, b;
  for (int i = 1; i <= 100; i++) d[i][1] = 1;
  for (int i = 1; i <= 40; i++) d[1][i] = i;
  for (int i = 2; i<= 100; i++) {
    for (int j = 2; j <= 40; j++) {
      d[i][j] = d[i-1][j-1] + d[i][j-1] + 1;
    }
  }
  while (scanf("%d%d", &b, &n) != -1 && (n | b) != 0) {
    if (b == 1) printf("%d\n", n);
    else if (b == 2) {
      int l = 1, r = 150;
      while (l < r) {
        int m = l + ((r-l)>>1);
        if (((m*(m+1))>>1) >= n) {
          r = m;
        } else {
          l = m+1;
        }
      }
      printf("%d\n", r);
    }
    else printf("%d\n", int(lower_bound(d[b], d[b]+41, n)-d[b]));
  }
  return 0;
}
