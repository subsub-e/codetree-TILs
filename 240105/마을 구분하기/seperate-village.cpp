#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[26][26];
int ans;
vector<int> v;
bool visited[26][26];

bool InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool cango(int x, int y){
    if(!InRange(x, y)){
        return false;
    }
    if(arr[x][y] == 0 || visited[x][y]){
        return false;
    }
    return true;
}

int dfs(int x, int y){
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    for(int i = 0; i < 4; i++){
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        if(cango(new_x, new_y)){
            visited[new_x][new_y] = 1;
            ans++;
            //cout << new_x << ' ' << new_y << ' ' << ans << '\n';
            dfs(new_x, new_y);
        }
    }
    return ans;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j] && arr[i][j] == 1){
                dfs(i, j);
                v.push_back(ans);
                ans = 0;
            }
        }
    }
    //dfs(0,0);
    cout << v.size() << '\n'; 
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        if(v[i] == 0){
            v[i] = 1;
        }
    }
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << '\n';
    }
    return 0;
}