#include <iostream>

using namespace std;

int n;
int dp[2000];
int main() {

    cin >> n;

    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= n; i++){
        int sum = 0;
        for(int j = 0; j < n; j++){
            sum += dp[j] * dp[i - j - 1];
        }
        dp[i] = sum;
    }
    cout << dp[n];
    return 0;
}