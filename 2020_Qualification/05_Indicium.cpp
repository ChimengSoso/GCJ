/**
 *    author:  ChimengSoso
 *    created: Fri Apr 10 2020 15:23:38
 *    file:    05_Indicium.cpp
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  // freopen("input.txt", "r", stdin);
  int tc; scanf("%d", &tc);
  for (int t = 1; t <= tc; ++t) {
    printf("Case #%d: ", t);
    int n, k; scanf("%d%d", &n, &k);

    if (k == n+1 || k == n*n-1 ||
       (n == 3 && (k == 5 || k == 7))) {
        printf("IMPOSSIBLE\n");
        continue;
    }

    // brute force find a, b, and c
    // that (n-2)*a + b + c = k and (iff a = b then a = c)
    int a, b, c{-1};
    for (a = 1; a <= n; ++a) {
        for (b = 1; b <= n; ++b) {
            c = k - (n-2)*a - b;
            if (1 <= c && c <= n &&
               ((a == b && a == c) ||
                (a != b && a != c) ) )
                break;
            c = -1;
        }
        if (c != -1) break;
    }
    if (c == -1) assert(false);

    printf("POSSIBLE\n");

    using vi = vector<int>;
    const int INF = 2e9;
    const int NIL = 0;

    vi d(n+1, a); d[1] = c, d[2] = b;
    vector<vi> mat(n+1, vi(n+1, 0));
    for (int i = 1; i <= n; ++i) mat[i][i] = d[i];

    vector<vi> adj;
    vector<int> pairU, pairV, dist;

    // Thanks algorithm : https://en.wikipedia.org/wiki/Hopcroft–Karp_algorithm
    auto bfs = [&](void) {
      queue<int> q;
      for (int u = 1; u <= n; ++u)
        if (pairU[u] == NIL)
          dist[u] = 0, q.push(u);
        else
          dist[u] = INF;
      dist[NIL] = INF;
      while (q.size()) {
        int u = q.front(); q.pop();
        if (dist[u] < dist[NIL])
          for (auto& v: adj[u])
            if (dist[pairV[v]] == INF)
              dist[pairV[v]] = dist[u] + 1,
              q.push(pairV[v]);
      }
      return dist[NIL] != INF;
    };

    function<bool(int)> dfs = [&](int u) {
      if (u == NIL) return true;
      for (auto& v: adj[u]) {
        if (dist[pairV[v]] == dist[u] + 1) {
          if (dfs(pairV[v])) {
            pairV[v] = u;
            pairU[u] = v;
            return true;
          }
        }
      }
      dist[u] = INF;
      return false;
    };

    auto hopcroftKrap = [&](int row) {
      pairV.assign(n+1, NIL);
      pairU.assign(n+1, NIL);
      dist.assign(n+1, INF);

      for (auto& node: adj) node.clear();
      adj.clear();
      adj.assign(n+1, vi());
      for (int col = 1; col <= n; ++col) {
        if (mat[row][col] == 0) {
          set<int> off_number;
          for (int i = 1; i <= n; ++i) {
            if (mat[i][col]) off_number.insert(mat[i][col]);
            if (mat[row][i]) off_number.insert(mat[row][i]);
          }
          
          for (int i = 1; i <= n; ++i)
            if (off_number.count(i) == 0)
              adj[col].push_back(i);
        } else {
          adj[col].push_back(mat[row][col]);
        }
      }

      int matching = 0;
      while (bfs()) {
        for (int u = 1; u <= n; ++u)
          if (pairU[u] == NIL && dfs(u))
              matching += 1;
      }
      return matching;
    };

    for (int i = 1; i <= n; ++i) {
      int matching = hopcroftKrap(i);
      assert(matching == n);
      copy(pairU.begin()+1, pairU.end(), mat[i].begin()+1);
    }

    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        printf("%d%c", mat[i][j], " \n"[j == n]);
  }
  return 0;
}