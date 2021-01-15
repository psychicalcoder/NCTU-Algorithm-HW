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
#include <queue>
#include <utility>
using namespace std;
typedef long long LL;
typedef pair<int, LL> P;

P ts[500005];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d%lld", &ts[i].first, &ts[i].second);
    }
    sort(ts, ts+n, [](const P& a, const P& b) {
      return a.first == b.first ? a.second > b.second : a.first < b.first;});
    priority_queue<LL, vector<LL>, greater<LL> > pq;
    for (int i = 0; i < n; i++) {
      if (pq.size() >= ts[i].first) {
        if (pq.top() < ts[i].second) {
          pq.pop();
          pq.push(ts[i].second);
        }
      } else {
        pq.push(ts[i].second);
      }
    }
    LL ans = 0;
    while (!pq.empty()) {
      ans += pq.top();
      pq.pop();
    }
    printf("%lld\n", ans);
  }
  return 0;
}
