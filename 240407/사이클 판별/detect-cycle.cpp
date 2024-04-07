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
    int indeg[n + 1] = {};
    vector<int> ans;
    queue<int> q;
    while(m--){
        int x1, x2;
        cin >> x1 >> x2;
        v[x1].push_back(x2);
        indeg[x2]++;
    }

    for(int i = 1; i <= n; i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        ans.push_back(cur);
        for(auto next : v[cur]){
            indeg[next]--;
            if(indeg[next] == 0){
                q.push(next);
            }
        }
    }

    if(ans.size() == n){
        cout << "Not Exists";
    }
    else{
        cout << "Exists";
    }
    return 0;
}