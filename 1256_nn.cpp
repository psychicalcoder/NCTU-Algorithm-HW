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

// The complexity of finding LIS and LDS is O(n^2)
// This code is for helping my roommate to debug.
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long LL;

int a[1005];
int lis[1005], di[1005];
int lds[1005], dd[1005];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int len;
    scanf("%d", &len);
    for (int i = 0; i < len; i++) {
      scanf("%d", &a[i]);
    }
    int l = 1;
    di[0] = a[0];
    lis[0] = 1;
    for (int i = 1; i < len; i++) {
      int j;
      for (j = 0; j < l; j++) {
        if (di[j] >= a[i])
          break;
      }
      if (j == l) {
        di[l++] = a[i];
        lis[i] = l;
      } else {
        di[j] = a[i];
        lis[i] = j + 1;
      }
    }
    reverse(a, a + len);
    l = 1;
    dd[0] = a[0];
    lds[0] = 1;
    for (int i = 1; i < len; i++) {
      int j;
      for (j = 0; j < l; j++) {
        if (dd[j] >= a[i])
          break;
      }
      if (j == l) {
        dd[l++] = a[i];
        lds[i] = l;
      } else {
        dd[j] = a[i];
        lds[i] = j + 1;
      }
    }
    // for (int i = 0; i < len; i++) {
    //   printf("%d ", lis[i]);
    // }
    // putchar('\n');
    // for (int i = 0; i < len; i++) {
    //   printf("%d ", lds[i]);
    // }
    int ans = 0;
    for (int i = 0; i < len; i++) {
      if (lis[i] != 1 && lds[len - i - 1] != 1)
        ans = max(ans, lis[i] + lds[len - i - 1] - 1);
    }
    printf("%d\n", len - ans);
  }
  return 0;
}
