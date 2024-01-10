#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, ans;
int dp_table[1005];
pair<int, int> line_pos[1005];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> line_pos[i].first >> line_pos[i].second;

  sort(line_pos + 1, line_pos + n + 1);
  dp_table[line_pos[1].second] = 1;
  for (int i = 2; i <= n; i++) {
    int start_pos = line_pos[i].first, end_pos = line_pos[i].second;
    for (int j = 1; j < start_pos; j++)
      dp_table[end_pos] = max(dp_table[end_pos], dp_table[j] + 1);
    dp_table[end_pos];
  }
  for (int i = 1; i <= 1000; i++)
    ans = max(ans, dp_table[i]);
  cout << ans;
  return 0;
};