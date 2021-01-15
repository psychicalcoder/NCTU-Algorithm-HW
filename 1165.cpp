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

int arr[1048580];

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
  int n, m;
  int piv = 0;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  for (int i = 1; i < n; i++) {
    if (arr[i] < arr[i - 1])
      piv = i;
  }
  while (m--) {
    int x;
    scanf("%d", &x);
    int ans1, ans2;
    ans1 = bsearch(0, piv, x);
    ans2 = bsearch(piv, n, x);
    if (ans1 != -1)
      printf("%d\n", ans1);
    else
      printf("%d\n", ans2);
  }
  return 0;
}
