#include <iostream>
#include <vector>
using namespace std;


int n, m, k;
vector<vector<int> > v(100001);
bool visited[100001];
int cnt;
vector<int> ans;

void dfs(int cur){
    for(auto next : v[cur]){
        if(!visited[next]){
            visited[next] = 1;
            dfs(next);
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        int x1, x2;
        cin >> x1 >> x2;
        v[x1].push_back(x2);
        v[x2].push_back(x1);
    }

    int start;
    for(int i = 0; i < k; i++){
        int x; cin >> x;
        start = x;
        ans.push_back(x);
    }
    visited[start] = 1;
    dfs(start);

    for(int i = 0; i < ans.size(); i++){
        if(!visited[ans[i]]){
            cout << 0;
            return 0;
        }
    }
    cout << 1;

    return 0;
}