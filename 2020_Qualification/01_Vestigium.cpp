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
    
    int row[n][n] = {}, col[n][n] = {}, nr[n] = {}, nc[n] = {}, k{};
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int m; scanf("%d", &m);
        if (i == j) k += m; --m;
        if (++row[i][m] >= 2) nr[i] = 1;
        if (++col[j][m] >= 2) nc[j] = 1;
      }
    }
    
    int r = 0, c = 0;
    for (int i = 0; i < n; ++i) r += nr[i], c += nc[i];
    printf("Case #%d: %d %d %d\n", t, k, r, c);
  }
  return 0;
}