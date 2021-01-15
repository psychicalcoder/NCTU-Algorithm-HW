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
#include <climits>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;

char s[505];
char str[505];
int d[505][505];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int len;
    int n = 1;
    scanf("%d%s", &len, str);
    s[0] = str[0];
    for (int i = 1; i < len; i++) {
      if (str[i - 1] != str[i])
        s[n++] = str[i];
    }
    s[n] = 0;
    memset(d, 0, sizeof(d));
    for (int i = 0; i < n; i++)
      d[i][i] = 1;
    for (int i = 1; i < n; i++) {
      for (int j = 0; i + j < n; j++) {
        int tm = INT_MAX;
        for (int k = 0; k < i; k++) {
          tm = min(tm, d[j][j + k] + d[j + k + 1][j + i]);
        }
        if (s[j] == s[j + i])
          tm--;
        d[j][j + i] = tm;
      }
    }
    printf("%d\n", d[0][n - 1]);
  }
  return 0;
}
