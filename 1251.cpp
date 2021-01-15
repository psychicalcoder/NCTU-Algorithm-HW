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
#include <algorithm>
using namespace std;

int main() {
  int num[7];
  while (scanf("%d%d%d%d%d%d", &num[1], &num[2], &num[3],
                               &num[4], &num[5], &num[6]) != EOF) {
    if (num[1] == 0 && num[2] == 0 && num[3] == 0 &&
        num[4] == 0 && num[5] == 0 && num[6] == 0) {
      break;
    }
    int ans = num[6];
    ans += num[5];
    num[1] = max(num[1]-num[5]*11, 0);
    ans += num[4];
    if (num[2] < num[4]*5) {
      num[1] = max(num[1]-(num[4]*5-num[2])*4, 0);
    }
    num[2] = max(num[2]-num[4]*5, 0);
    ans += num[3]/4;
    num[3] = num[3]%4;
    if (num[3] > 0) {
      ans += 1;
    }
    if (num[3] == 1) {
      if (5 > num[2]) {
        num[1] = max(num[1]-(5-num[2])*4, 0);
      }
      num[1] = max(num[1]-7, 0);
      num[2] = max(num[2]-5, 0);
    } else if (num[3] == 2) {
      if (3 > num[2]) {
        num[1] = max(num[1]-(3-num[2])*4, 0);
      }
      num[1] = max(num[1]-6, 0);
      num[2] = max(num[2]-3, 0);
    } else if (num[3] == 3) {
      if (1 > num[2]) {
        num[1] = max(num[1]-(1-num[2])*4, 0);
      }
      num[1] = max(num[1]-5, 0);
      num[2] = max(num[2]-1, 0);
    }
    ans += num[2]/9;
    num[2] = num[2]%9;
    if (num[2] > 0) {
      ans += 1;
      num[1] = max(num[1] - (9-num[2])*4, 0);
    }
    ans += num[1]/36;
    if (num[1]%36 > 0) ans += 1;
    printf("%d\n", ans);
  }
  return 0;
}
