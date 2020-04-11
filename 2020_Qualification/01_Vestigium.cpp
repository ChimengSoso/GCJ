/**
 *    author:  ChimengSoso
 *    created: Fri Apr 10 2020 13:51:39
 *    file:    01_Vestigium.cpp
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  // freopen("input.txt", "r", stdin);
  int tc; scanf("%d", &tc);
  for (int t = 1; t <= tc; ++t) {
    int n; scanf("%d", &n);
    
    int row[n+1][n+1] = {}, nr[n+1] = {},
        col[n+1][n+1] = {}, nc[n+1] = {}, k{};
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        int m; scanf("%d", &m);
        if (i == j) k += m;
        if (++row[i][m] >= 2) nr[i] = 1;
        if (++col[j][m] >= 2) nc[j] = 1;
      }
    }
    
    int r = accumulate(nr+1, nr+n+1, 0),
        c = accumulate(nc+1, nc+n+1, 0);
    printf("Case #%d: %d %d %d\n", t, k, r, c);
  }
  return 0;
}