#include <iostream>
using namespace std;

int n, m, x, y;
int arr[100][100];

bool InRange(int a, int b){
    return 0 <= a && a <= n && 0 <= b && b <= n;
}

void simulate(int t){
    int temp[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            temp[i][j] = arr[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(temp[i][j] == 1){
                if(InRange(i - t, j)){
                    arr[i - t][j] = 1;
                }
                if(InRange(i, j - t)){
                    arr[i][j - t] = 1;
                }
                if(InRange(i + t, j)){
                    arr[i + t][j] = 1;
                }
                if(InRange(i, j + t)){
                    arr[i][j + t] = 1;
                }
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m >> x >> y;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            arr[i][j] = 0;
        }
    }
    x--;
    y--;
    arr[x][y] = 1;
    for(int i = 1; i <= m; i++){
        simulate(i);
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == 1){
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}