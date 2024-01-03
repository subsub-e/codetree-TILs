#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n;
int arr[10];
int ans = INT_MAX;

void simulate(int x, int count){
    if(arr[x] == 0){
        return;
    }
    if(x == n-1){
        ans = min(ans, count);
        //cout << ans << '\n';
        return;
    }

    //cout << x << ' ' << count << '\n';
    for(int i = 1; i <= arr[x]; i++){
        simulate(x + i, count + 1);
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    simulate(0, 0);
    if(ans == INT_MAX){
        cout << -1;
        return 0;
    }
    cout << ans;
    return 0;
}