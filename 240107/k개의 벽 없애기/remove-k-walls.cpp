#include <iostream>
#include <vector>
#include <tuple>
#include <climits>
#include <queue>
#include <algorithm>
using namespace std;

int n, a;
int arr[100][100];
bool visited[100][100];
int step[100][100];
int wall[8][2];
int ans = INT_MAX;
int start_x, start_y;
int end_x, end_y;
vector<int> combination;
int cnt = 0;
queue<pair<int, int>> q;

bool cango(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < n && !visited[x][y] && !arr[x][y];
}

void push(int x, int y, int q_cnt){
    visited[x][y] = 1;
    step[x][y] = q_cnt;
    if(x == end_x && y == end_y){
        //cout << step[x][y] << '\n';
        ans = min(ans, step[x][y]);
    }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << step[i][j] << ' ';
    //     }
    //         cout << '\n';
    //     }
    // cout << '\n';
    q.push(make_pair(x, y));
}

void bps(){
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
}

void initalize(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            visited[i][j] = 0;
            step[i][j] = 0;
        }
    }
}

void FindCombination(int curr_num, int count) {

    // n개의 숫자를 모두 탐색했으면 더 이상 탐색하지 않습니다.
    if(curr_num == cnt) {
        // 탐색하는 과정에서 m개의 숫자를 뽑은 경우 답을 출력해줍니다.
        if(count == a){
            initalize();
            for(int i = 0; i < combination.size(); i++){
                int ppp = combination[i];
                //cout << ppp << '\n';
                //cout << wall[ppp][0] << ' ' << wall[ppp][1] << '\n';
                arr[wall[ppp][0]][wall[ppp][1]] = 0;
            }
            // for(int i = 0; i < n; i++){
            //     for(int j = 0; j < n; j++){
            //         cout << arr[i][j] << ' ';
            //     }
            //     cout << '\n';
            // }
            // cout << '\n';
            push(start_x, start_y, 0);
            bps();
            for(int i = 0; i < combination.size(); i++){
                int ppp = combination[i];
                arr[wall[ppp][0]][wall[ppp][1]] = 1;
            }
        }
        return;
    }

    // curr_num에 해당하는 숫자를 사용했을 때의 경우를 탐색합니다.
    combination.push_back(curr_num);
    FindCombination(curr_num + 1, count + 1);
    combination.pop_back();

    // curr_num에 해당하는 숫자를 사용하지 않았을 때의 경우를 탐색합니다.
    FindCombination(curr_num + 1, count);
}


int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> a;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1){
                wall[cnt][0] = i;
                wall[cnt][1] = j;
                //cout << i << ' ' << j << '\n';
                cnt++;
            }
        }
    }
    cin >> start_x >> start_y >> end_x >> end_y;
    start_x--;
    start_y--;
    end_x--;
    end_y--;
    FindCombination(0, 0);
    if(ans == INT_MAX){
        cout << -1;
        return 0;
    }
    cout << ans;
    return 0;
}