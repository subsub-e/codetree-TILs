#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;

int n, m;
int arr[101][101];
const int INF = 0x3f3f3f3f;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        fill(arr[i], arr[i] + 1 + n, INF);
        arr[i][i] = 0;
    }

    while(m--){
        int x1, x2, cost;
        cin >> x1 >> x2 >> cost;
        arr[x1][x2] = cost;
        //arr[x2][x1] = cost;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    int minans = INT_MAX;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j){
                continue;
            }
            minans = min(minans, arr[i][j] + arr[j][i]);
        }
    }
    cout << minans;
    return 0;
}