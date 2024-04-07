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
    queue<int> q;
    vector<int> ans;
    
    for(int i = 1; i <= m; i++){
        int x1, x2;
        cin >> x1 >> x2;
        v[x1].push_back(x2);
        indig[x2]++;
    }

    for(int i = 1; i <= n; i++){
        if(indig[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        //cout << cur << ' ';
        ans.push_back(cur);
        for(auto next : v[cur]){
            indig[next]--;
            if(indig[next] == 0){
                q.push(next);
            }
        }
    }

    // for(int i = 0; i < ans.size(); i++){
    //     cout << ans[i] << ' ';
    // }
    if(ans.size() == n){
        cout << "Consistent";
    }
    else{
        cout << "Inconsistent";
    }
    return 0;
}