/**
 *    author:  ChimengSoso
 *    created: Fri Apr 10 2020 14:40:35
 *    file:    04_ESAb_ATAd.cpp
**/
#include <bits/stdc++.h>
using namespace std;

void rev(vector<char>& s) {reverse(s.begin()+1, s.end()); }

void tog(vector<char>& s) {
  for (int i = 1; i <= s.size()-1; ++i) {
    if (s[i] == -1) continue;
    s[i] = (s[i] == '0' ? '1' : '0');
  }
}

char read(int idx) {
  cout << idx << endl;
  char rlt; cin >> rlt;
  return rlt;
}

int main() {
  // freopen("input.txt", "r", stdin);
  int t, b; scanf("%d%d", &t, &b);
  while (t--) {
    int s{1}, e{b}, same{-1}, diff{-1};
    vector<char> bit(b+1, -1);
    for (int i = 0; i < 5; ++i, ++s, --e) {
      bit[s] = read(s), bit[e] = read(e);
      if (bit[s] == bit[e]) same = s;
      if (bit[s] != bit[e]) diff = s;
    }
    while (s < e) {
      if (same != -1 && diff != -1) {
        // has same and diff index of value in bit
        char new_same = read(same);
        char new_diff = read(diff);
        if (new_same == bit[same] && new_diff != bit[diff]) {
          // observe that system choose order `reverse`
          // when same index is same but diff isn't
          rev(bit);
        } else if (new_same != bit[same] && new_diff != bit[diff]) {
          // observe that system choose order `tog`
          // when any index is different from old value
          tog(bit);
        } else if (new_same != bit[same] && new_diff == bit[diff]) {
          // observe that system choose order `rev + tog`
          // when same index isn't same
          //  and diff -> [change] from rev -> [change] from tog
          //  So, diff is not change
          rev(bit);
          tog(bit);
        }
      } else if (same != -1) {
        // has only same index of value in bit
        char new_same = read(same);
             new_same = read(same);
        if (new_same != bit[same]) tog(bit); // Or tog + rev
      } else if (diff != -1) {
        // has only diff index of value in bit
        char new_diff = read(diff);
             new_diff = read(diff);
        if (new_diff != bit[diff]) rev(bit); // Or tog
      }

      for (int i = 0; i < 4 && s < e; ++i, ++s, --e) {
        bit[s] = read(s), bit[e] = read(e);
        if (bit[s] == bit[e]) same = s;
        if (bit[s] != bit[e]) diff = s;
      }
    }
    
    cout << string(bit.begin()+1, bit.end()) << endl;
    char reply; cin >> reply;
    if (reply == 'N') exit(0);
  }
  return 0;
}