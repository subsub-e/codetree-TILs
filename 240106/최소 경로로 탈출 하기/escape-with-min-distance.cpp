#include <iostream>
#include <queue>
using namespace std;

int n, m;
int arr[100][100];
int step[100][100];
bool visited[100][100];
queue<pair<int, int>> q;

bool cango(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m && !visited[x][y] && arr[x][y];
}

void push(int x, int y, int s){
    step[x][y] = s;
    visited[x][y] = 1;
    q.push(make_pair(x, y));
}

void bps(){
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    while(!q.empty()) {
        pair<int, int> curr_pos = q.front();
        q.pop();

        int x = curr_pos.first;
        int y = curr_pos.second;
        for(int i = 0; i < 4; i++){
            int pos_x = x + dx[i];
            int pos_y = y + dy[i];
            if(cango(pos_x, pos_y)){
                push(pos_x, pos_y, step[x][y] + 1);
            }
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
    push(0, 0, 0);
    bps();
    //for(int i = 0; i < n; i++)
    if(step[n-1][m-1] == 0){
        cout << -1;
        return 0;
    }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << step[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << step[n-1][m-1];
    return 0;
}