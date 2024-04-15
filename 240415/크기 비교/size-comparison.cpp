#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
int arr[101][101];
const int INF= 0x3f3f3f3f;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    if(m == 0){
        for(int i = 1; i <= n; i++){
            cout << n-1 << '\n';
        }
    }
    for(int i = 1; i <= n; i++){
        fill(arr[i], arr[i] + 1 + n, INF);
        arr[i][i] = 1;
    }

    while(m--){
        int x1, x2; cin >> x1 >> x2;
        arr[x1][x2] = 1;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(arr[i][j] >= arr[i][k] + arr[k][j]){
                    arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
                    arr[k][i] = 1;
                }
            }
        }
    }

    for(int i = 1; i <= n; i++){
        int cnt = 0;
        for(int j = 1; j <= n; j++){
            if(arr[i][j] >= INF){
                cnt++;
            }
        }
        if(cnt == n-1){
            cout << 0 << '\n';
        }
        else{
            cout << cnt << '\n';
        }
        
    }
    return 0;
}