/**
 *    author:  ChimengSoso
 *    created: Fri Apr 10 2020 14:20:37
 *    file:    03_Parenting_Partnering_ReturnsV2.cpp
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  // freopen("input.txt", "r", stdin);
  int tc; scanf("%d", &tc);
  for (int t = 1; t <= tc; ++t) {
    int n; scanf("%d", &n);
    using pii = pair<int, int>;
    vector<pii> job(n, pii());
    for (auto& e: job) scanf("%d%d", &e.first, &e.second);

    printf("Case #%d: ", t);
    vector<vector<int>> gph(n);
    for (int i = 0; i < n; ++i) {
      for (int j = i+1; j < n; ++j) {
        int s1 = job[i].first;
        int t1 = job[i].second;
        int s2 = job[j].first;
        int t2 = job[j].second;
        if (max(s1, s2) < min(t1, t2)) {
          gph[i].push_back(j);
          gph[j].push_back(i);
        }
      }
    }

    vector<int> color(n, -1);
    bool isPossible = true;
    function<void(int, int)> dfs = [&](int u, int c) {
      if (color[u] != -1) return;
      color[u] = c;
      for (int& v: gph[u]) {
        if (color[v] == -1) {
          dfs(v, c^1);
        }
        if (color[v] != c^1) {
          isPossible= false;
          return;
        }
      }
    };

    for (int i = 0; i < n; ++i) dfs(i, 0);
    if (!isPossible) printf("IMPOSSIBLE");
    else for (int& e: color) {
      assert(e != -1);
      printf("%c", e ? 'J':'C');
    }
    printf("\n");
  }
  return 0;
}