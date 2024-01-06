#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n, m;
int arr[101][101];
bool visited[101][101];
queue<int> q;

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m;
}

bool cango(int x, int y){
    if(!InRange(x, y)){
        return false;
    }
    if(visited[x][y] || arr[x][y] == 0){
        return false;
    }
    return true;
}

bool bps(int x, int y){
    if(x == n - 1 && y == m - 1){
        cout << 1;
        exit(0);
    }
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    for(int i = 0; i < 4; i++){
        int pos_x = x + dx[i];
        int pos_y = y + dy[i];

        if(cango(pos_x, pos_y)){
            visited[pos_x][pos_y] = 1;
            bps(pos_x, pos_y);
        }
    }
    return false;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    bps(0 ,0);
    cout << 0;
    return 0;
}