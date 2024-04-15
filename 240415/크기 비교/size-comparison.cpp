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

    while(m--){
        int x1, x2; cin >> x1 >> x2;
        arr[x1][x2] = 1;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(arr[i][k] && arr[k][j]){
                    arr[i][j] = 1;
                }
            }
        }
    }

    for(int i = 1; i <= n; i++){
        int cnt = 0;
        for(int j = 1; j <= n; j++){
            if(i == j || arr[i][j] || arr[j][i]){
                continue;
            }
            cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}