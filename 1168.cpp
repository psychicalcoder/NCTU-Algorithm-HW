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
#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;

bool cmp(const string &a, const string &b) {
  string s = a + b;
  string t = b + a;
  return s > t;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    string s;
    vector<string> v;
    for (int i = 0; i < n; i++) {
      cin >> s;
      v.push_back(s);
    }
    sort(v.begin(), v.end(), cmp);
    for (string str : v)
      cout << str;
    cout << '\n';
  }
  return 0;
}
