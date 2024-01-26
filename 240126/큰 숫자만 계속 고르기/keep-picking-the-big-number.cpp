#include <iostream>
#include <queue>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m; cin >> n >> m;
    priority_queue<int> pq;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        pq.push(a);
    }
    for(int i = 0; i < m; i++){
        int ans = pq.top();
        pq.pop();
        ans--;
        pq.push(ans);
    }
    cout << pq.top();
    return 0;
}