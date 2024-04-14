#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, p, q;
int arr[201][201];
const int INF = 0x3f3f3f3f;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m >> p >> q;
    for(int i = 1; i <= n; i++){
        fill(arr[i], arr[i] + n + 1, INF);
        arr[i][i] = 0;
    }

    while(m--){
        int x, y, cost;
        cin >> x >> y >> cost;
        arr[x][y] = cost;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    long long ans = 0;
    int cnt = 0;

    for(int i = 1; i <= q; i++){
        int x, y;
        cin >> x >> y;
        int distance = INF;

        for(int j = 1; j <= p; j++){
            distance = min(distance, arr[x][j] + arr[j][y]);
        }

        if(distance >= INF){
            continue;
        }
        ans += distance;
        cnt++;
    }
    cout << cnt << '\n' << ans;
    return 0;
}