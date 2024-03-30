#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int n, m, k;
int arr[101][101];
bool visited[101][101];
bool ans[101][101];
int maxans;
queue<pair<int, int> > q;
vector<pair<int, int> > stone;
vector<pair<int, int> > start;
vector<int> v;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void bfs(){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        ans[x][y] = 1;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < n && arr[nx][ny] == 0 && !visited[nx][ny]){
                visited[nx][ny] = 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

void func(int x, int y, int cnt){
    if(v.size() == k){
        memset(visited, 0, sizeof(visited));
        //memset(ans, 0, sizeof(ans));
        for(int i = 0; i < k; i++){
            int stone_x = stone[v[i]].first;
            int stone_y = stone[v[i]].second;
            arr[stone_x][stone_y] = 0;
        }

        for(int i = 0; i < start.size(); i++){
            int start_x = start[i].first;
            int start_y = start[i].second;
            q.push(make_pair(start_x, start_y));
            visited[start_x][start_y] = 1;
        }
        
        bfs();

        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(ans[i][j] == 1){
                    cnt++;
                }
            }
        }
        maxans = max(maxans, cnt);

        for(int i = 0; i < k; i++){
            int stone_x = stone[v[i]].first;
            int stone_y = stone[v[i]].second;
            arr[stone_x][stone_y] = 1;
        }
        return;
    }
    

    for(int i = cnt; i < stone.size(); i++){
        v.push_back(i);
        func(x, y, i + 1);
        v.pop_back();
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1){
                stone.push_back(make_pair(i, j));
            }
        }
    }

    for(int i = 0; i < m; i++){
        
        int x1, x2;
        cin >> x1 >> x2;
        start.push_back(make_pair(x1, x2));
    }
    
    cout << maxans;
    return 0;
}