#include <iostream>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m, k; cin >> n >> m >> k;
    int arr[n][m];
    int presumA[n+1][m+1] = {};
    int presumB[n+1][m+1] = {};
    int presumC[n+1][m+1] = {};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c; cin >> c;
            arr[i][j] = (int) c - 97;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(arr[i-1][j-1] == 0){
                presumA[i][j] = presumA[i-1][j] + presumA[i][j-1] - presumA[i-1][j-1] + 1;
                presumB[i][j] = presumB[i-1][j] + presumB[i][j-1] - presumB[i-1][j-1];
                presumC[i][j] = presumC[i-1][j] + presumC[i][j-1] - presumC[i-1][j-1];
            }
            else if(arr[i-1][j-1] == 1){
                presumA[i][j] = presumA[i-1][j] + presumA[i][j-1] - presumA[i-1][j-1];
                presumB[i][j] = presumB[i-1][j] + presumB[i][j-1] - presumB[i-1][j-1]+1;
                presumC[i][j] = presumC[i-1][j] + presumC[i][j-1] - presumC[i-1][j-1];
            }
            else if(arr[i-1][j-1] == 2){
                presumA[i][j] = presumA[i-1][j] + presumA[i][j-1] - presumA[i-1][j-1];
                presumB[i][j] = presumB[i-1][j] + presumB[i][j-1] - presumB[i-1][j-1];
                presumC[i][j] = presumC[i-1][j] + presumC[i][j-1] - presumC[i-1][j-1] + 1;
            }
        }
    }
    // for(int i = 0; i <= n; i++){
    //     for(int j = 0; j <= m; j++){
    //         cout << presumC[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    for(int i = 0; i < k; i++){
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        int sumA = presumA[x2][y2] + presumA[x1-1][y1-1] - presumA[x1-1][y2] - presumA[x2][y1-1];
        int sumB = presumB[x2][y2] + presumB[x1-1][y1-1] - presumB[x1-1][y2] - presumB[x2][y1-1];
        int sumC = presumC[x2][y2] + presumC[x1-1][y1-1] - presumC[x1-1][y2] - presumC[x2][y1-1];
        cout << sumA << ' ' << sumB << ' ' << sumC << '\n';
    }
    return 0;
}