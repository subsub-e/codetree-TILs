#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int n, m, ans;
int arr[251][251];
int d[251];
int path[251];
bool visited[251];
const int INF = 1e9 + 10;

void func(){
    fill(d, d + n + 1, INF);
    fill(visited, visited + n + 1, 0);
    d[1] = 0;
    //priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    //pq.push(make_pair(d[1], 1));

    for(int i = 1; i <= n; i++){
        int min_idx = -1;
        for(int j = 1; j <= n; j++){
            if(visited[j]){
                continue;
            }
            if(min_idx == -1 || d[min_idx] > d[j]){
                min_idx = j;
            }
        }

        visited[min_idx] = 1;

        for(int j = 1; j <= n; j++){
            if(arr[min_idx][j] == 0){
                continue;
            }
            if(d[j] > d[min_idx] + arr[min_idx][j]){
                d[j] = d[min_idx] + arr[min_idx][j];
                path[j] = min_idx;
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;

    while(m--){
        int x1, x2, cost;
        cin >> x1 >> x2 >> cost;
        arr[x1][x2] = cost;
        arr[x2][x1] = cost;
    }

    func();

    int x = n;
    vector<int> v;
    v.push_back(x);
    while(x != 1){
        x = path[x];
        v.push_back(x);
    }

    int min_dist = d[n];

    for(int i = (int)v.size() - 1; i >= 1; i--){
        int x = v[i];
        int y = v[i-1];
        arr[x][y] *= 2;
        arr[y][x] *= 2;
        func();

        ans = max(ans, d[n] - min_dist);

        arr[x][y] /= 2;
        arr[y][x] /= 2;
    }

    cout << ans;


    return 0;
}