#include <iostream>
#include <algorithm>
using namespace std;

int a;
int num[4][4];
int dir[4][4];
int ans;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool InRange(int x, int y){
    return 0 <= x && x < a && 0 <= y && y < a;
}

bool end(int x, int y){
    int flag = 0;
    for(int i = 1; i < a; i++){
        int pos_x = x + (dx[dir[x][y]] * i);
        int pos_y = y + (dy[dir[x][y]] * i);
        if(InRange(pos_x, pos_y) && num[pos_x][pos_y] > num[x][y]){
            flag = 1;
        }
    }
    if(flag == 0){
        return true;
    }
    return false;
}

void simulate(int x, int y, int count){
    if(end(x, y)){
        ans = max(ans, count);
        return;
    }

    for(int i = 1; i < a; i++){
        int pos_x = x + (dx[dir[x][y]] * i);
        int pos_y = y + (dy[dir[x][y]] * i);
        if(InRange(pos_x, pos_y) && num[pos_x][pos_y] > num[x][y]){
            //cout << pos_x << ' ' << pos_y << ' ' << count << '\n';
            simulate(pos_x, pos_y, count + 1);
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> a;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++){
            cin >> num[i][j];
        }
    }
    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++){
            int num;
            cin >> num;
            num--;
            dir[i][j] = num;
        }
    }
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    simulate(x, y, 0);
    cout << ans;
    return 0;
}