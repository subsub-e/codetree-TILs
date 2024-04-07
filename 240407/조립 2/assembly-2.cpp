#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int n, m; cin >> n >> m;
    vector<vector<int> > v(n + 1);
    queue<int> q;
    vector<int> ans;
    int indeg[n + 1] = {};
    bool visited[n + 1] = {};

    while(m--){
        int x, cnt;
        cin >> x >> cnt;
        while(cnt--){
            int x2; cin >> x2;
            v[x2].push_back(x);
            indeg[x]++;
        }
    }

    int k;
    cin >> k;
    while(k--){
        int pre; cin >> pre;
        //indeg[pre] = 0;
        q.push(pre);

        visited[pre] = 1;
        //ans.push_back(pre);
    }

    // for(int i = 1; i <= n; i++){
    //     cout << indeg[i] << ' ';
    // }
    // cout << '\n';

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        ans.push_back(cur);
        for(auto next : v[cur]){
            if(visited[next]){
                continue;
            }
            //cout << next << '\n';
            indeg[next]--;
            if(indeg[next] == 0){
                q.push(next);
                visited[next] = 1;
            }
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << ' ';
    }
    return 0;
}