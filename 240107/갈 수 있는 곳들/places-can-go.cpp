#include <iostream>
using namespace std;

int n, m;
int arr[100][100];
bool visited[100][100] = {};
int cnt = 0;

bool cango(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n && !visited[x][y] && !arr[x][y];
}

void bps(int x, int y){
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    for(int i = 0; i < 4; i++){
        int pos_x = x + dx[i];
        int pos_y = y + dy[i];
        if(cango(pos_x, pos_y)){
            visited[pos_x][pos_y] = 1;
            cnt++;
            bps(pos_x, pos_y);
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    if(n == 1){
        cout << 1;
        return 0;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        cnt++;
        if(visited[x][y]){
            cnt--;
        }
        visited[x][y] = 1;
        bps(x, y);
    }
    cout << cnt;
    return 0;
}