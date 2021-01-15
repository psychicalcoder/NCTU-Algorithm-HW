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
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;
  string line, l2;
  while (T--) {
    cin >> line;
    for (int i = 0; i < line.length(); i++) {
      if (line[i] == '{' || line[i] == ',' || line[i] == ':' ||
          line[i] == '}') {
        line[i] = ' ';
      }
    }
    cin >> l2;
    for (int i = 0; i < l2.length(); i++) {
      if (l2[i] == '{' || l2[i] == ',' || l2[i] == ':' || l2[i] == '}') {
        l2[i] = ' ';
      }
    }
    stringstream ss, ss2;
    // cout << line << endl << l2 << endl << "Te" << endl;
    ss << line;
    string k, v;
    map<string, string> m1;
    while (ss >> k) {
      ss >> v;
      m1[k] = v;
    }
    ss2 << l2;
    map<string, string> m2;
    while (ss2 >> k) {
      ss2 >> v;
      m2[k] = v;
    }
    map<string, string>::iterator iter = m1.begin();
    vector<string> plus, mod, rm;
    while (iter != m1.end()) {
      if (!m2.count(iter->first))
        rm.push_back(iter->first);
      else if (m2[iter->first] != iter->second)
        mod.push_back(iter->first);
      iter++;
    }
    iter = m2.begin();
    while (iter != m2.end()) {
      if (!m1.count(iter->first))
        plus.push_back(iter->first);
      iter++;
    }
    bool ans = false;
    if (plus.size() >= 1) {
      cout << "+" << plus[0];
      for (int i = 1; i < plus.size(); i++) {
        cout << "," << plus[i];
      }
      cout << endl;
      ans = true;
    }
    if (rm.size() >= 1) {
      cout << "-" << rm[0];
      for (int i = 1; i < rm.size(); i++) {
        cout << "," << rm[i];
      }
      cout << endl;
      ans = true;
    }
    if (mod.size() >= 1) {
      cout << "*" << mod[0];
      for (int i = 1; i < mod.size(); i++) {
        cout << "," << mod[i];
      }
      cout << endl;
      ans = true;
    }
    if (!ans) {
      cout << "No changes" << endl;
    }
    cout << endl;
  }
  return 0;
}
