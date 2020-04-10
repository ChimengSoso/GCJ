/**
 *    author:  ChimengSoso
 *    created: Fri Apr 10 2020 14:09:42
 *    file:    03_Parenting_Partnering_ReturnsV1.cpp
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
  // freopen("input.txt", "r", stdin);
  int tc; scanf("%d", &tc);
  for (int t = 1; t <= tc; ++t) {
    int n; scanf("%d", &n);
    
    using tiii = tuple<int, int, int>;
    vector<tiii> job(n, tiii());
    for (int i = 0; i < n; ++i) {
      int s, t; scanf("%d%d", &s, &t);
      job[i] = tiii(s, t, i);
    }

    printf("Case #%d: ", t);
    
    enum {BEGIN, END, IDX};
    sort(job.begin(), job.end());
    
    vector<char> rlt(n, -1);
    
    tiii none = tiii(-1, -1, -1);
    tiii cameron = none, jamie = none;
    for (auto& e: job) {
      if (cameron == none || get<END>(cameron) <= get<BEGIN>(e)) {
        cameron = e;
        rlt[get<IDX>(e)] = 'C';        
      } else if (jamie == none || get<END>(jamie) <= get<BEGIN>(e)) {
        jamie = e;
        rlt[get<IDX>(e)] = 'J';
      }
    }
    printf("%s\n", find(rlt.begin(), rlt.end(), -1) != rlt.end() ? 
                   "IMPOSSIBLE" :  
                   string(rlt.begin(), rlt.end()).c_str());
  }
  return 0;
}