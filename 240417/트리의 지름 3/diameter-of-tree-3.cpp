#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cstring>
#include <queue>
using namespace std;

int n;
vector<pair<int, int> > v[100001];
int root, result;
int d[100001];
bool visited[100001];
priority_queue<int> pq;

void dfs(int x, int len){
    if(visited[x]){
        return;
    }
    visited[x] = 1;
    if(result < len){
        root = x;
        result = len;
    }
    pq.push(len);

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
    //cout << root << '\n';
    dfs(root, 0);

    pq.pop();
    pq.pop();
    cout << pq.top();

    return 0;
}