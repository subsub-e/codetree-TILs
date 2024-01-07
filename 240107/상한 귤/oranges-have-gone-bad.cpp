#include <iostream>
#include <tuple>
#include <queue>
#include <vector>
using namespace std;

int a, b;
int arr[100][100];

vector<pair<int, int> > v;

bool visited[100][100];
int step[100][100];
queue<pair<int, int>> q;
int answer[100][100];

bool cango(int x, int y){
    return 0 <= x && x < a && 0 <= y && y < a && !visited[x][y] && arr[x][y] != 0;
}

void Push(int x, int y, int cnt){
    visited[x][y] = 1;
    step[x][y] = cnt;
    q.push(make_pair(x, y));
}

void bps(){
    while(!q.empty()){
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        pair<int, int> curr_pos = q.front();
        q.pop();

        int x = curr_pos.first;
        int y = curr_pos.second;

        for(int i = 0; i < 4; i++){
            int pos_x = x + dx[i];
            int pos_y = y + dy[i];

            if(cango(pos_x, pos_y)){
                Push(pos_x, pos_y, step[x][y] + 1);
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a >> b;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 2){
                v.push_back(make_pair(i, j));
            }
        }
    }
    for(int i = 0; i < b; i++){
        Push(v[i].first, v[i].second, 0);
    }
    bps();

    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++){
            if(arr[i][j] == 0){
                cout << -1 << ' ';
            }
            else{
                if(!visited[i][j]){
                    cout << -2 << ' ';
                }
                else{
                    cout << step[i][j] << ' ';
                }
            }
        }
        cout << '\n';
    }
    return 0;
}