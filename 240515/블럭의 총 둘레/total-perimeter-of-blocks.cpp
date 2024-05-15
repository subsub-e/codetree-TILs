#include <iostream>

#define MAX_N 100

using namespace std;

int n;
int already_visited[MAX_N + 2][MAX_N + 2];
int occupied[MAX_N + 2][MAX_N + 2];
int perimeter;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

// x, y 좌표가 유효한지 확인하는 함수입니다.
int valid(int x, int y) {
    return x >= 0 && x <= MAX_N + 1 && y >= 0 && y <= MAX_N + 1;
}

// (x, y) 좌표를 방문하는 함수입니다.
// 이미 방문했거나 occupied인 경우에는 방문하지 않습니다.
void visit(int x, int y) {
    if(occupied[x][y]) {
        perimeter++; 
        return; 
    }
    if(already_visited[x][y]) return;
    already_visited[x][y] = 1;
    
    // 주변 방향을 검사합니다.
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(valid(nx, ny)) visit(nx, ny);
    }
}

int main() {
    // 변수를 입력받습니다.
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        occupied[x][y] = 1;
    }

    visit(0, 0);

    // 결과를 출력합니다.
    cout << perimeter << endl;
    return 0;
}