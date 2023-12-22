#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, k; cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int ans = INT_MAX;
    for(int i = 1; i < 10000; i++){
        int cost = 0;

        for(int j = 0; j < n; j++){
            if(arr[j] < i){
                cost += i - arr[j];
            }
            if(arr[j] > i + k){
                cost += arr[j] - (i + k);
            }
        }
        ans = min(ans, cost);
    }
    cout << ans;
    return 0;
}