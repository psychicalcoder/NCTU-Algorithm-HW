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

// The complexity of finding LIS and LDS is O(nlogn)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
#include <climits>
using namespace std;

typedef long long LL;

int a[1005], ar[1005];
int lis[1005], lds[1005];
int bi[1005], bd[1005];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int len;
    scanf("%d", &len);
    for (int i = 0; i < len; i++) {
      scanf("%d", &a[i]);
    }
    for (int i = 0; i < len; i++) {
      ar[i] = a[len-1-i];
    }
    memset(lis, 0, sizeof(lis));
    memset(lds, 0, sizeof(lds));
    bi[0] = bd[0] = -1;
    for (int i = 1; i <= len; i++) bi[i] = bd[i] = INT_MAX;
    for (int i = 0; i < len; i++) {
      int dpi = lower_bound(bi, bi+i+1, a[i]) - bi - 1;
      int dpd = lower_bound(bd, bd+i+1, ar[i]) - bd - 1;
      lis[i] = dpi+1;
      lds[i] = dpd+1;
      if (bi[dpi+1] > a[i]) bi[dpi+1] = a[i];
      if (bd[dpd+1] > ar[i]) bd[dpd+1] = ar[i];
    }
    // for (int i = 0; i < len; i++) {
    //   printf("%d ", lis[i]);
    // }
    // puts("");
    // for (int i = 0; i < len; i++) {
    //   printf("%d ", lds[len-i-1]);
    // }
    // puts("");
    int ansc = 0;
    for (int i = 0; i < len; i++) {
      if (lis[i] != 1 && lds[len-i-1] != 1) {
        ansc = max(ansc, lis[i]+lds[len-i-1]);
      }
    }
    if (ansc == 0) printf("%d\n", len);
    else printf("%d\n", len-ansc+1);
  }
  return 0;
}
