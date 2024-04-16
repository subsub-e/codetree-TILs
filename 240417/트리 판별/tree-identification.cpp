#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v[10001];
bool visited[10001];
bool root_node[10001];
int node[10001];
int ans = 0;
int root;

void dfs(int x){
    if(visited[x]){
        return;
    }
    visited[x] = 1;
    ans++;

    for(auto next : v[x]){
        dfs(next);
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    int cnt = 0;
    
    for(int i = 0; i < n; i++){
        int x1, x2;
        cin >> x1 >> x2;
        root_node[x1] = 1;
        root_node[x2] = 1;
        node[x2]++;
        cnt++;
        if(node[x2] > 1){
            cout << 0;
            return 0;
        }
        v[x1].push_back(x2);
    }

    for(int i = 1; i <= 10000; i++){
        if(root_node[i] == 1 && node[i] == 0){
            root = i;
        }
    }

    if(root == 0){
        cout << 0;
        return 0;
    }
    dfs(root);
    if(ans - 1 == cnt){
        cout << 1;
    }
    else{
        cout << 0;
    }
    return 0;
}