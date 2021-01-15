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
#include <stack>
#include <cstring>
using namespace std;
typedef long long LL;

char s[130];

int main() {
  int cases;
  scanf("%d", &cases);
  fgets(s, 130, stdin);
  while(cases--) {
    stack<char> stk;
    bool ans = true;
    fgets(s, 130, stdin);
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
      if (s[i] == '\n') break;
      if (s[i] == '[' || s[i] == '(') {
        stk.push(s[i]);
      } else {
        if (stk.empty()) {
          ans = false;
          break;
        }
        if (s[i] == ']') {
          if (stk.top() != '[') {
            ans = false;
            break;
          } else {
            stk.pop();
          }
        } else if (s[i] == ')') {
          if (stk.top() != '(') {
            ans = false;
            break;
          } else {
            stk.pop();
          }
        }
      }
    }
    if (!stk.empty()) ans = false;
    printf("%s\n", ans ? "Yes" : "No");
  }
  return 0;
}
