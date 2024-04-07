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
    for(int i = 1; i <= m; i++){
        int x1, x2;
        cin >> x1 >> x2;
        v[x1].push_back(x2);
        indig[x2]++;
    }

    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(indig[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for(auto next : v[cur]){
            
            indig[next]--;
            //cout << indig[next] << '\n';
            if(indig[next] == 0){
                q.push(next);
            }
        }
    }
    return 0;
}