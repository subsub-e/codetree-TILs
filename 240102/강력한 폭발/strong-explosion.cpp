#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int a;
int arr[20][20];
int bombed[20][20];

vector<pair<int, int>> v;
int ans = 0;

bool InRange(int x, int y) {
    return 0 <= x && x < a && 0 <= y && y < a;
}

void Bomb(int x, int y, int b_type) {
    // 폭탄 종류마다 터질 위치를 미리 정의합니다.
    pair<int, int> bomb_shapes[4][5] = {
        {},
        { {-2, 0}, {-1, 0}, {0, 0},  {1, 0}, {2, 0}},
        { {-1, 0},  {1, 0}, {0, 0}, {0, -1}, {0, 1}},
        {{-1, -1}, {-1, 1}, {0, 0}, {1, -1}, {1, 1}}
    };
    
    // 격자 내 칸에 대해서만 영역을 표시합니다.
    for(int i = 0; i < 5; i++) {
        int dx, dy;
        tie(dx, dy) = bomb_shapes[b_type][i];
        
        int nx = x + dx, ny = y + dy;
        if(InRange(nx, ny))
            bombed[nx][ny] = true;
    }
}

int Calc() {
    for(int i = 0; i < a; i++){
        for(int j = 0; j <a; j++){
            bombed[i][j] = 0;
        }
    }

    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++){
            if(arr[i][j]){
                Bomb(i, j, arr[i][j]);
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++){
            if(bombed[i][j])
            cnt++;
        }
    }
    return cnt;
}

void simulate(int cnt){

    if(cnt == (int) v.size()){
        ans = max(ans, Calc());
        return;
    }
    
    for(int i = 1; i <= 3; i++){
        int x, y;
        tie(x, y) = v[cnt];

        arr[x][y] = i;
        simulate(cnt + 1);
        //arr[x][y] = 0;
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++){
            int bomb;
            cin >> bomb;
            if(bomb){
                v.push_back(make_pair(i, j));
            }
        }
    }
    simulate(0);
    cout << ans;
    return 0;
}