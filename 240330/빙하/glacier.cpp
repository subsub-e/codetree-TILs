#include <iostream>
#include <queue>
#include <algorithm>

enum ELEMENT {
    WATER,
    GLACIER  
};

#define DIR_NUM 4
#define MAX_N 200
#define MAX_M 200

using namespace std;

// 전역 변수 선언:
int n, m;

int a[MAX_N][MAX_M];

// bfs에 필요한 변수들 입니다.
queue<pair<int, int> > q;
bool visited[MAX_N][MAX_N];
int cnt;

int dx[DIR_NUM] = {1, -1, 0, 0};
int dy[DIR_NUM] = {0, 0, 1, -1};

// 소요 시간과 가장 마지막으로 녹은 빙하의 수를 저장합니다.
int elapsed_time, last_melt_cnt;

// 범위가 격자 안에 들어가는지 확인합니다.
bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

// 범위를 벗어나지 않으면서 물이여야 하고 방문한적이 
// 없어야 갈 수 있습니다.
bool CanGo(int x, int y) {
    return InRange(x, y) && a[x][y] == WATER && !visited[x][y];
}

// visited 배열을 초기화합니다.
void Initialize() {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            visited[i][j] = 0;
}

// 빙하에 둘러쌓여 있지 않은 물들을 전부 구해주는 BFS입니다.
// 문제에서 가장자리는 전부 물로 주어진다 했기 때문에
// 항상 (0, 0)에서 시작하여 탐색을 진행하면
// 빙하에 둘러쌓여 있지 않은 물들은 전부 visited 처리가 됩니다.
void BFS() {
    // BFS 함수가 여러 번 호출되므로
    // 사용하기 전에 visited 배열을 초기화 해줍니다.
    Initialize();

    // 항상 (0, 0)에서 시작합니다.
    q.push(make_pair(0, 0));
    visited[0][0] = true;

    while(!q.empty()) {
        // queue에서 가장 먼저 들어온 원소를 뺍니다.
        pair<int, int> curr_pos = q.front();
        int x = curr_pos.first, y = curr_pos.second;
        q.pop();

        // queue에서 뺀 원소의 위치를 기준으로 4 방향을 확인합니다.
        for(int dir = 0; dir < DIR_NUM; dir++) {
            int nx = x + dx[dir], ny = y + dy[dir];

            // 더 갈 수 있는 곳이라면 Queue에 추가합니다.
            if(CanGo(nx, ny)) {
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
            }
        }
    }
}

// 현재 위치를 기준으로 인접한 영역에
// 빙하에 둘러쌓여 있지 않은 물이 있는지를 판단합니다.
bool OutsideWaterExistInNeighbor(int x, int y) {
    for(int dir = 0; dir < DIR_NUM; dir++) {
        int nx = x + dx[dir], ny = y + dy[dir];
        if(InRange(nx, ny) && visited[nx][ny])
            return true;
    }

    return false;
}

// 인접한 영역에 빙하에 둘러쌓여 있지 않은 물이 있는 빙하를 찾아
// 녹여줍니다.
void Melt() {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j] == GLACIER && 
               OutsideWaterExistInNeighbor(i, j)) {
                a[i][j] = WATER;
                last_melt_cnt++;
            }
}

// 빙하를 한 번 녹입니다.
void Simulate() {
    elapsed_time++;
    last_melt_cnt = 0;

    // 빙하에 둘러쌓여 있지 않은 물의 위치를 전부 
    // visited로 체크합니다.
    BFS();

    // 인접한 영역에 빙하에 둘러쌓여 있지 않은 물이 있는 빙하를 찾아
    // 녹여줍니다.
    Melt();
}

// 빙하가 아직 남아있는지 확인합니다.
bool GlacierExist() {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j] == GLACIER)
                return true;

    return false;
}

int main() {
    // 입력:
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    
    do {
        // 빙하를 한 번 녹입니다. 
        Simulate();
    } while(GlacierExist()); // 빙하가 존재하는 한 계속 반복합니다.

    // 출력:
    cout << elapsed_time << " " << last_melt_cnt;

    return 0;
}