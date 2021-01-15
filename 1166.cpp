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

int a[100005];

int main() {
  int T, n;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int mxcont = 1;
    int cont = 1, kind = 1;
    for (int i = 1; i < n; i++) {
      if (a[i] != a[i - 1]) {
        kind++;
        if (mxcont < cont)
          mxcont = cont;
        cont = 1;
      } else
        cont++;
    }
    if (mxcont < cont)
      mxcont = cont;
    // printf("mx %d kd %d\n", mxcont, kind);
    if (kind > mxcont)
      printf("%d\n", mxcont);
    else if (kind == mxcont)
      printf("%d\n", kind - 1);
    else
      printf("%d\n", kind);
  }
}
