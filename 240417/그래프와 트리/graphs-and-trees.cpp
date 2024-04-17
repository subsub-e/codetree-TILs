#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v[501];
bool visited[501];
int edge;
int node;

void dfs(int x){
    for(auto next : v[x]){
        edge++;
        if(visited[next]){
            continue;
        }
        visited[next] = 1;
        node++;
        dfs(next);
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x1, x2;
        cin >> x1 >> x2;
        v[x1].push_back(x2);
        v[x2].push_back(x1);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(visited[i]){
            continue;
        }
        node = 0;
        edge = 0;
        visited[i] = 1;
        node++;
        dfs(i);
        edge /= 2;
        if(node == edge + 1){
            ans++;
        }
        //cout << i << ' ' << node << ' ' << edge << '\n';
    }

    cout << ans << '\n';
    return 0;
}