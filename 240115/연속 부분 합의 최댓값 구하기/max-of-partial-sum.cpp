#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int a;
int arr[100001];
int sum[100001];

void init(){
    for(int i = 0; i < a; i++){
        sum[i] = INT_MIN;
    }
    sum[0] = 2 * arr[0];
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a;
    for(int i = 0; i < a; i++){
        cin >> arr[i];
    }
    init();
    for(int i = 1; i < a; i++){
        sum[i] = max(sum[i-1] + arr[i], arr[i]);
    }
    int ans = INT_MIN;
    for(int i = 0; i < a; i++){
        //cout << sum[i] << ' ';
        ans = max(ans, sum[i]);
    }
    cout << ans;
    return 0;
}