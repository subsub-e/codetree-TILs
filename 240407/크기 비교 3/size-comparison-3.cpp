#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m;
    cin >> n >> m;
    vector<vector<int> > v(n + 1);
    int indig[n + 1] = {};
    priority_queue<int, vector<int>, greater<int> > pq;
    while(m--){
        int x1, x2;
        cin >> x1 >> x2;
        v[x1].push_back(x2);
        indig[x2]++;
    }

    for(int i = 1; i <= n; i++){
        if(indig[i] == 0){
            pq.push(i);
        }
    }

    while(!pq.empty()){
        int cur = pq.top();
        pq.pop();
        cout << cur << ' ';
        for(auto next : v[cur]){
            indig[next]--;
            if(indig[next] == 0){
                pq.push(next);
            }
        }
    }

    return 0;
}