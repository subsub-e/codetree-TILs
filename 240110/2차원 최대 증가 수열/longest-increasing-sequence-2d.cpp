#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;
int n, m, ans;
int arr[55][55];
int dp[55][55];
void Initailize() {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      dp[i][j] = 0;
  dp[1][1] = 1;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      cin >> arr[i][j];

  Initailize();

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int x = 1; x < i; x++) {
        for (int y = 1; y < j; y++) {
          if (arr[x][y] < arr[i][j] && dp[x][y] > 0)
            dp[i][j] = max(dp[i][j], dp[x][y] + 1);
        }
      }
    }
  }
//   for (int i = 1; i <= n; i++){
//     for (int j = 1; j <= m; j++){
//         cout << dp[i][j] << ' ';
//     }
//     cout << '\n';
      
//   }
    
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      ans = max(ans, dp[i][j]);
  cout << ans;
  return 0;
}