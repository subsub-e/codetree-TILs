#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;

int n, m;
int s1, s2, e;
int arr[101][101];
const int INF = 0x3f3f3f3f;

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m >> s1 >> s2 >> e;
    for(int i = 1; i <= n; i++){
        fill(arr[i], arr[i] + n + 1, INF);
        arr[i][i] = 0;
    }
    for(int i = 0; i < m; i++){
        int x1, x2, cost;
        cin >> x1 >> x2 >> cost;
        arr[x1][x2] = cost;
        arr[x2][x1] = cost;
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
        if(i == s1 || i == s2){
            continue;
        }
        minans = min(minans, arr[s1][i] + arr[s2][i] + arr[i][e]);
    }
    cout << minans;
    return 0;
}