/**
 *    author:  ChimengSoso
 *    created: Fri Apr 10 2020 13:47:21
 *    file:    02_Nesting_Depth.cpp
**/
#include <bits/stdc++.h>
using namespace std;

string sol(string& s, int i, int d, string ans) {
  if (i == s.size()) return ans;
  if (d  < s[i]-'0') return sol(s, i+0, d+1, ans +  "(");
  if (d == s[i]-'0') return sol(s, i+1, d+0, ans + s[i]);
  if (d  > s[i]-'0') return sol(s, i+0, d-1, ans +  ")");
}

int main() {
  // freopen("input.txt", "r", stdin);
  int tc; scanf("%d", &tc);
  for (int t = 1; t <= tc; ++t) {
    string in; cin >> in; in += "0";
    
    string ans = sol(in, 0, 0, ""); ans.back() = 0;
    printf("Case #%d: %s\n", t, ans.c_str());
  }
  return 0;
}