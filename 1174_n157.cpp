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

// The complexity of this version is O(n^1.57)
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <utility>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;

char s1[200005], s2[200005];

bool solution(int s1l, int s2l, int len) {
  if (len & 1) {
    for (int i = 0; i < len; i++) {
      if (s1[s1l + i] != s2[s2l + i])
        return false;
    }
    return true;
  } else {
    int half = len >> 1;
    bool ans1 =
        solution(s1l, s2l, half) && solution(s1l + half, s2l + half, half);
    if (ans1)
      return true;
    bool ans2 =
        solution(s1l, s2l + half, half) && solution(s1l + half, s2l, half);
    if (ans2)
      return true;
  }
  return false;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s%s", s1, s2);
    puts(solution(0, 0, strlen(s1)) ? "Yes" : "No");
  }
  return 0;
}
