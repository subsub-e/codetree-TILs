#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
bool visited[10001];
vector<pair<int, int> > v[10001];
int root, result;

void dfs(int x, int len){
    if(visited[x]){
        return;
    }
    visited[x] = 1;
    
    if(result < len){
        result = len;
        root = x;
    }

    for(auto next : v[x]){
        dfs(next.first, len + next.second);
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    int temp;
    for(int i = 0; i < n; i++){
        int x1, x2, cost;
        cin >> x1 >> x2 >> cost;
        temp = x2;
        v[x1].push_back(make_pair(x2, cost));
        v[x2].push_back(make_pair(x1, cost));
    }

    dfs(temp, 0);
    memset(visited, 0, sizeof(visited));

    dfs(root, 0);

    cout << result;

    return 0;
}