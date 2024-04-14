#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
int arr[101][101];
const int INF = 0x3f3f3f3f;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        fill(arr[i], arr[i] + 1 + n, INF);
    }

    for(int i = 1; i <= n; i++){
        arr[i][i] = 0;
    }

    for(int i = 0; i < m; i++){
        int x1, x2, cost;
        cin >> x1 >> x2 >> cost;
        arr[x1][x2] = min(arr[x1][x2], cost);
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(arr[i][j] == INF{
                cout << -1 << ' ';
                continue;
            }
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}