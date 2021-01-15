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
#include <utility>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;

P arr[1000005];

bool cmp(const P &a, const P &b) {
  return a.first * a.first + a.second * a.second <
         b.first * b.first + b.second * b.second;
}

bool cmp2(const P &a, const P &b) {
  if (a.first == b.first)
    return a.second > b.second;
  else
    return a.first > b.first;
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &arr[i].first, &arr[i].second);
  }
  sort(arr, arr + n, cmp);
  sort(arr, arr + k, cmp2);
  for (int i = 0; i < k; i++) {
    printf("%d %d\n", arr[i].first, arr[i].second);
  }
  return 0;
}
