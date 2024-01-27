#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a, b; cin >> a >> b;
    int arr[a+1][a+1] = {};
    int sum[a + 1][a + 1] = {};
    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= a; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= a; j++){
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + arr[i][j];
        }
    }
    int maxans = 0;
    for(int i = b; i <= a; i++){
        for(int j = b; j <= a; j++){
            int sum1 = sum[i][j] - sum[i-b][j] - sum[i][j-b] + sum[i-b][j-b];
            maxans = max(maxans, sum1);
        }
        //cout << '\n';
    }
    cout << maxans;
    return 0;
}