#include <iostream>
//#include <algorithm>
using namespace std;

int n, m;
int arr[50][50];
int visited[50][50] = {};



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
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    for(int i = 0; i < 4; i++){
        int pos_x = x + dx[i];
        int pos_y = y + dy[i];
        if(cango(pos_x, pos_y)){
            visited[pos_x][pos_y] = 1;
            dfs(pos_x, pos_y);
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    int max_k = 0;
    int max = 0;
    int ans = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            if(max_k < arr[i][j]){
                max_k = arr[i][j];
            }
        }
    }
    for(int i = 1; i < max_k; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                if(arr[j][k] <= i){
                    arr[j][k] = 0;
                }
            }
        }
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                visited[j][k] = 0;
            }
        }
        
        int cnt = 0;
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                if(arr[j][k] != 0 && !visited[j][k]){
                    //cout << j << ' ' << k << '\n';
                    dfs(j, k);
                    cnt++;
                }
            }
        }
        if(max < cnt){
            max = cnt;
            ans = i;
        }
    }
    cout << ans << ' ' << max;
    return 0;
}