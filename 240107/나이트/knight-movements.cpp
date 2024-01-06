#include <iostream>
#include <queue>
#include <tuple>
#include <climits>
#include <algorithm>
using namespace std;

int n;
queue<pair<int, int>> q;
bool visited[100][100];
int step[100][100];
int r2, c2;
int minans = INT_MAX;

bool cango(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n && !visited[x][y];
}

void push(int x, int y, int cnt){
    visited[x][y] = 1;
    step[x][y] = cnt;
    if(x == r2 && y == c2){
        //cout << step
        minans = min(minans, step[x][y]);
    }
    //cout << x << ' ' << y << ' ' << step[x][y] << '\n';
            
    q.push(make_pair(x, y));
}

void bps(){
    int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

    while(!q.empty()){
        pair<int, int> curr_pos = q.front();
        q.pop();

        int x = curr_pos.first;
        int y = curr_pos.second;
        

        for(int i = 0; i < 8; i++){
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
    cin >> n;
    int r1, c1;
    cin >> r1 >> c1 >> r2 >> c2;
    r1--;
    c1--;
    r2--;
    c2--;
    push(r1, c1, 0);
    bps();
    if(minans == INT_MAX){
        cout << -1;
        return 0;
    }
    cout << minans;
    return 0;
}