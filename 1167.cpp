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
using namespace std;
typedef long long LL;

int arr[1000005];

int bsearch(int l, int r, int x) {
  while (l < r) {
    int mid = (l + r) >> 1;
    if (arr[mid] == x)
      return mid;
    else if (arr[mid] > x) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  return -1;
}

int main() {
  int m, n, k;
  scanf("%d%d%d", &m, &n, &k);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) {
      scanf("%d", &arr[i * n + j]);
    }
  while (k--) {
    int x;
    scanf("%d", &x);
    int ans = bsearch(0, m * n, x);
    if (ans != -1)
      printf("%d %d\n", ans / n, ans % n);
    else
      puts("-1");
  }
  return 0;
}
