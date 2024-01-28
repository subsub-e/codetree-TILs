#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    int arr[a][2];
    int left[a] = {};
    int right[a] = {};
    int minans = INT_MAX;

    for(int i = 0; i < a; i++){
        for(int j = 0; j < 2; j++){
            cin >> arr[i][j];
        }
    }
    
    for(int i = 1; i < a; i++){
        left[i] = left[i - 1] + abs(arr[i][0] - arr[i-1][0]) + abs(arr[i][1] - arr[i-1][1]);
    }

    for(int i = a-2; i >= 0; i--){
        right[i] = right[i + 1] + abs(arr[i + 1][0] - arr[i][0]) + abs(arr[i + 1][1] - arr[i][1]);
    }

    for(int i = 1; i < a; i++){
        int ans = left[i - 1] + right[i + 1] + abs(arr[i + 1][0] - arr[i - 1][0]) + abs(arr[i + 1][1] - arr[i - 1][0]);
        minans = min(minans, ans);
    }
    cout << minans;
    return 0;
}