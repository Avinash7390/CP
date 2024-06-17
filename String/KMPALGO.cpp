
#include<bits/stdc++.h>
 
using namespace std;
int kmp(string String, string pattern) {
  int i = 0, j = 0, m = pattern.length(), n = String.length();
  pattern = ' ' + pattern; //just shifting the pattern indices by 1
  vector < int > piTable(m + 1, 0);
  for (int i = 2; i <= m; i++) {
    while (j <= m && pattern[j + 1] == pattern[i])
      piTable[i++] = ++j;
    j = 0;
  }
  j = 0;
  for (int i = 0; i < n; i++) {
    if (pattern[j + 1] != String[i]) {
      while (j != 0 && pattern[j + 1] != String[i])
        j = piTable[j];
    }
    j++;
    if (j == m) return i - m + 1;
  }
  return -1;

}
int main() {
  string pattern="aaaaaab", String="aaaaaaaamaaaaaab";

  int index = kmp(String, pattern);
  if (index == -1) cout << "The pattern is not found";
  else cout << "The pattern " << pattern << " is found in the given string " 
  << String << " at " << index;
  return 0;
}



Time Complexity = O(m + n)
