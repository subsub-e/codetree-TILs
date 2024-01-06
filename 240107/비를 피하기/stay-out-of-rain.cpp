#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <climits>
using namespace std;

int n, h, m;
queue<pair<int, int>> q;
bool visited[100][100];
int step[100][100];
vector<pair<int, int>> v;
int arr[100][100];
int minans = INT_MAX;

bool cango(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n && !visited[x][y] && arr[x][y] != 1;
}

void push(int x, int y, int num){
    visited[x][y] = 1;
    step[x][y] = num;
    if(arr[x][y] == 3){
        minans = min(minans, step[x][y]);
    }
    q.push(make_pair(x, y));
}

int bps(){
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    while(!q.empty()){
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

    if(minans == INT_MAX){
        return -1;
    }
    return minans;
}


int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> h >> m;
    int answer[n][n] = {};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == 2){
                push(i, j, 0);
                answer[i][j] = bps();
                minans = INT_MAX;
                for(int l = 0; l < n; l++){
                    for(int k = 0; k < n; k++){
                        step[l][k] = 0;
                        visited[l][k] = 0;
                    }
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << answer[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}