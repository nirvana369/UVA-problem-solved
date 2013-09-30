#include <cstdio>
#include <algorithm>
#include <string>

#define fi "760.inp"
#define fo "760.out"
using std::string;
 
int main() {
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
  int first = 1;
  while (1) {
    if (!first) {
      char tmp[10];
      if (!gets(tmp)) break;
      puts("");
    }
    first = 0;
    char s1[310], s2[310];
    gets(s1 + 1);
    gets(s2 + 1);
    int i, j, lcs[310][310] = {}, N = 0, max = 0;
    for (i = 1; s1[i]; i++)
      for (j = 1; s2[j]; j++)
        if (s1[i] == s2[j]) {
          lcs[i][j] = lcs[i - 1][j - 1] + 1;
          if (lcs[i][j] > max) max = lcs[i][j];
        } else lcs[i][j] = 0;
    if (max < 1) {
      puts("No common sequence.");
      continue;
    }
    string ans[10000];
    int k = 0;
    for (i = 1; s1[i]; i++)
      for (j = 1; s2[j]; j++)
        if (lcs[i][j] == max)
          ans[k++] = string(s1 + i - max + 1, s1 + i + 1);
    sort(ans, ans + k);
    for (i = 0; i < k; i++)
      if (i && !(ans[i].compare(ans[i - 1]))) continue;
      else puts(ans[i].c_str());
  }
  return 0;
}
