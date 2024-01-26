#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m; cin >> n >> m;
    priority_queue<tuple<int, int, int> > pq;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        pq.push(make_tuple(-(a + b), -a, -b));
    }
    for(int i = 0; i < m; i++){
        int x, y;
        tie(ignore, x, y) = pq.top();
        x -= 2;
        y -= 2;
        pq.pop();
        pq.push(make_tuple((x + y), x, y));
    }
    int nx, ny;
    tie(ignore, nx, ny) = pq.top();
    cout << -nx << ' ' << -ny;
    return 0;
}