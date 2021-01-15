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
#include <list>
using namespace std;
typedef long long LL;

int main() {
  string line;
  while(getline(cin, line)) {
    string s = "";
    list<string> lst;
    int prev = 0; // 0 == back 1 == front
    for (int i = 0; i < line.length(); i++) {
      if (line[i] == '[') {
        if (s.length() > 0) {
          if (prev) {
            lst.push_front(s);
          } else {
            lst.push_back(s);
          }
        }
        prev = 1;
        s = "";
      }
      else if (line[i] == ']') {
        if (s.length() > 0) {
          if (prev) {
            lst.push_front(s);
          } else {
            lst.push_back(s);
          }
        }
        prev = 0;
        s = "";
      } else {
        s += line[i];
      }
    }
    if (s.length() > 0) {
      if (prev) {
        lst.push_front(s);
      } else {
        lst.push_back(s);
      }
    }
    for (string str : lst) {
      cout << str;
    }
    cout << endl;
  }
  return 0;
}
