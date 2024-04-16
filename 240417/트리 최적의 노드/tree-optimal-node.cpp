#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
vector<int> v[100001];
bool visited[100001];
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
        dfs(next, len + 1);
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    int temp;
    for(int i = 0; i < n-1; i++){
        int x1, x2;
        cin >> x1 >> x2;
        temp = x2;
        v[x1].push_back(x2);
        v[x2].push_back(x1);
    }

    dfs(temp, 0);
    memset(visited, 0, sizeof(visited));
    dfs(root, 0);

    cout << (result+1) / 2;
    return 0;
}