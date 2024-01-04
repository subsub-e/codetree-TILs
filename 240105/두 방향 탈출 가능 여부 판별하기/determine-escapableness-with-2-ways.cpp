#include <iostream>
using namespace std;

int n, m;
int arr[101][101];
bool visited[101][101];

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

void dfs(int x, int y){
    //cout << x << ' ' << y << '\n';
    if(x == n - 1 && y == n - 1){
        cout << 1;
        exit(0);
    }

    int dx[2] = {1, 0};
    int dy[2] = {0, 1};

    for(int i = 0; i < 2; i++){
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if(cango(new_x, new_y)){
            visited[new_x][new_y] = 1;
            dfs(new_x, new_y);
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

    dfs(0,0);
    cout << 0;
    return 0;
}