#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int n, k, u, d;
int arr[9][9];
bool visited[9][9];
queue<pair<int, int> > q;
vector<int> v;
vector<pair<int, int> > start;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int maxans;

void bfs(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < n && !visited[nx][ny]){
                int temp = abs(arr[nx][ny] - arr[x][y]);
                if(temp >= u && temp <= d){
                    visited[nx][ny] = 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

void func(int cur){
    if(v.size() == k){
        memset(visited, 0, sizeof(visited));
        for(int i = 0; i < k; i++){
            int start_x = start[v[i]].first;
            int start_y = start[v[i]].second;
            q.push(make_pair(start_x, start_y));
            visited[start_x][start_y] = 1;
        }

        bfs();

        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(visited[i][j] == 1){
                    cnt++;
                }
            }
        }
        maxans = max(maxans, cnt);
    }

    



    for(int i = cur; i < n * n; i++){
        v.push_back(i);
        func(i + 1);
        v.pop_back();
    }
}


int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> k >> u >> d;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            start.push_back(make_pair(i, j));
        }
    }

    func(0);
    cout << maxans;
    return 0;
}