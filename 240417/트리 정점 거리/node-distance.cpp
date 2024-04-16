#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
vector<pair<int, int> > v[1001];
bool visited[1001];

void dfs(int start, int end, int len){
    if(start == end){
        cout << len << '\n';
        return;
    }

    for(auto next : v[start]){
        if(visited[next.first]){
            continue;
        }
        visited[next.first] = 1;
        dfs(next.first, end, len + next.second);
    }
    return;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    for(int i = 0; i < n-1; i++){
        int x1, x2, cost;
        cin >> x1 >> x2 >> cost;
        v[x1].push_back(make_pair(x2, cost));
        v[x2].push_back(make_pair(x1, cost));
    }

    while(m--){
        int x1, x2;
        cin >> x1 >> x2;
        memset(visited, 0, sizeof(visited));
        visited[x1] = 1;
        dfs(x1, x2, 0);
    }
    return 0;
}