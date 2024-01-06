#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[101][101];
bool visited[101][101];
vector<int> v;
int ans;

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool cango(int x, int y, int num){
    if(!InRange(x, y)){
        return false;
    }
    if(visited[x][y] || arr[x][y] != num){
        return false;
    }
    return true;
}

void dfs(int x, int y, int num){
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    for(int i = 0; i < 4; i++){
        int pos_x = x + dx[i];
        int pos_y = y + dy[i];
        if(cango(pos_x, pos_y, num)){
            visited[pos_x][pos_y] = 1;
            ans++;
            dfs(pos_x, pos_y, num);
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    int max_n = 0;
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            if(max_n < arr[i][j]){
                max_n = arr[i][j];
            }
        }
    }
    for(int i = 1; i <= max_n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(!visited[j][k] && arr[j][k] == i){
                    dfs(j, k, i);
                    v.push_back(ans);
                    ans = 0;
                }
            }
        }
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i] >= 4){
            cnt++;
        }
    }
    cout << cnt << ' ' << v[v.size() - 1];
    return 0;
}