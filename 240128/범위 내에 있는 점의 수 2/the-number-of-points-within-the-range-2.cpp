#include <iostream>
using namespace std;

int arr[1000001];
int sum[1000002];
int n, q;


int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        int c;
        cin >> c;
        arr[c] = 1;
    }
    for(int i = 1; i <= 1000002; i++){
        sum[i] = sum[i-1] + arr[i-1];
    }
    for(int i = 0; i < q; i++){
        int x, y; cin >> x >> y;
        int ans = sum[y + 1] - sum[x];
        cout << ans << '\n';
    }
    return 0;
}