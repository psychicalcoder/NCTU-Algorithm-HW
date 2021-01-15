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
#include <cstring>
#include <functional>
using namespace std;
typedef long long LL;

char a[500005];
char b[500005];
char c[500005];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s%s", a, b);
    int len = strlen(a);
    sort(a, a+len);
    sort(b, b+len, greater<char>());
    int ah = 0, at, bh = 0, bt;
    if (len & 1) {
      at = (len>>1);
      bt = (len>>1)-1;
    } else {
      at = bt = (len>>1)-1;
    }
    
    //printf("len = %d\nah %d at %d bh %d bt %d\n", len, ah, at, bh, bt);
    c[len] = '\0';
    int ch = 0, ct = len-1;
    for (int i = 0; i < len; i++) {
      if ((i&1) == 0) { // a turn
        if (a[ah] >= b[bh]) {
          c[ct--] = a[at--];
        } else {
          c[ch++] = a[ah++];
        }
      } else { // a turn
        if (b[bh] <= a[ah]) {
          c[ct--] = b[bt--];
        } else {
          c[ch++] = b[bh++];
        }
      }
    }
    puts(c);
  }
  return 0;
}
