#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int par[51];
vector<int> v[51];
int root;
int ans;
bool visited[51];
void dfs(int x){
    if(visited[x]){
        return;
    }

    int flag = 0;

    for(auto next : v[x]){
        if(par[x] == next){
            continue;
        }
        if(visited[next]){
            continue;
        }
        dfs(next);
        flag = 1;
    }

    if(flag == 0){
        ans++;
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> par[i];
        int x = i;
        int y = par[i];

        if(y == -1){
            root = x;
            continue;
        }

        v[y].push_back(x);
    }

    int node; cin >> node;

    visited[node] = 1;
    dfs(root);

    cout << ans;
    return 0;
}