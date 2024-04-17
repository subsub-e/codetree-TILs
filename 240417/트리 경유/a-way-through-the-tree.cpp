#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m;
int arr[1048577];
bool visited[1048577];

void dfs(int now, int start){
    if(visited[now]){
        cout << now << '\n';
        return;
    }
    if(now == 1){
        cout << 0 << '\n';
        visited[start] = 1;
        return;
    }

    if(now % 2 == 1){
        dfs((now - 1) / 2, start);
    }
    else{
        dfs(now / 2, start);
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    while(m--){
        int x; cin >> x;
        dfs(x, x);
        //cout << '\n';
    }
    return 0;
}