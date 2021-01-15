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
#include <vector>
using namespace std;
typedef long long LL;

vector<int> G[205];

int low[205], vis[205];
bool instk[205];
int stk[205];
int tp, cnt, stamp;
int color[205];

void tarjan(int x) {
  low[x] = vis[x] = ++stamp;
  stk[tp++] = x;
  instk[x] = true;
  for (int i = 0, y; i < G[x].size(); i++) {
    y = G[x][i];
    if (!vis[y])
      tarjan(y);
    if (instk[y])
      low[x] = min(low[x], low[y]);
  }
  if (vis[x] == low[x]) {
    int u;
    do {
      instk[u = stk[--tp]] = false;
      color[u] = cnt;
    } while (u != x);
    cnt++;
  }
}

bool dfsvis[205];
void dfs(int x) {
  dfsvis[x] = true;
  for (int i = 0; i < G[x].size(); i++) {
    int y = G[x][i];
    if (!dfsvis[y])
      dfs(y);
  }
}

int main() {
  int N, M;
  while (scanf("%d%d", &N, &M) != -1 && (N | M) != 0) {
    tp = 0;
    cnt = 0;
    stamp = 0;
    memset(instk, false, sizeof(instk));
    memset(vis, 0, sizeof(vis));
    memset(stk, 0, sizeof(stk));
    memset(low, 0, sizeof(low));
    for (int i = 2; i <= 2 * N + 1; i++)
      G[i].clear();
    for (int i = 0; i < M; i++) {
      char s[5];
      int K, wk;
      int wks[4], tks[4];
      scanf("%d", &K);
      for (int j = 0; j < K; j++) {
        scanf("%d%s", &wk, s);
        wks[j] = wk;
        tks[j] = s[0] == 'a' ? 1 : 0;
      }
      if (K < 3) {
        for (int j = 0; j < K; j++) {
          if (tks[j] == 1) {
            G[(wks[j] << 1) + 1].push_back(wks[j] << 1);
          } else {
            G[(wks[j] << 1)].push_back((wks[j] << 1) + 1);
          }
        }
      } else {
        for (int p = 0; p < K; p++) {
          for (int q = 0; q < K; q++) {
            if (p == q)
              continue;
            G[(wks[p] << 1) + (tks[p] ? 1 : 0)].push_back((wks[q] << 1) +
                                                          (tks[q] ? 0 : 1));
          }
        }
      }
    }
    // for (int i = 1; i <= N; i++) {
    //	printf("%d ->", i);
    //	for (int j : G[i<<1]) printf(" %d", j);
    //	putchar('\n');
    //	printf("not %d ->", i);
    //	for (int j : G[(i<<1)+1]) printf(" %d", j);
    //	putchar('\n');
    //}
    for (int i = 2; i <= (2 * N + 1); i++) {
      if (!vis[i])
        tarjan(i);
    }
    // for (int i = 2; i <= (2*N+1); i++) {
    //	printf("%d ->", i);
    //	for (int j : G[i]) printf(" %d", j);
    //	putchar('\n');
    //}
    bool ok = true;
    // for (int i = 2; i <= (2*N+1); i++) printf("%d %d\n", i, color[i]);
    for (int i = 1; i <= N; i++) {
      if (color[i << 1] == color[(i << 1) + 1])
        ok = false;
    }

    if (ok == false) {
      puts("It's treason, then.");
      continue;
    }

    bool a_nota, nota_a;
    for (int i = 1; i <= N; i++) {
      a_nota = nota_a = false;
      memset(dfsvis, false, sizeof(dfsvis));
      dfs(i << 1);
      if (dfsvis[(i << 1) + 1])
        a_nota = true;
      memset(dfsvis, false, sizeof(dfsvis));
      dfs((i << 1) + 1);
      if (dfsvis[(i << 1)])
        nota_a = true;
      if ((!a_nota) && (!nota_a))
        putchar('p');
      else
        putchar(a_nota ? 'n' : 'y');
    }
    putchar('\n');
  }
  return 0;
}
