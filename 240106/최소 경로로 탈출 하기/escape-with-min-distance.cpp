#include <iostream>
using namespace std;

int n, m;
int arr[100][100];
int step[100][100];
bool visited[100][100];

bool cango(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m && !visited[x][y] && arr[x][y];
}

void bps(int x, int y){
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    for(int i = 0; i < 4; i++){
        int pos_x = x + dx[i];
        int pos_y = y + dy[i];
        if(cango(pos_x, pos_y)){
            visited[pos_x][pos_y] = 1;
            step[pos_x][pos_y] = step[x][y] + 1;
            bps(pos_x, pos_y);
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    visited[0][0] = 1;
    step[0][0] = 0;
    bps(0, 0);
    //for(int i = 0; i < n; i++)
    cout << step[n-1][m-1];
    return 0;
}