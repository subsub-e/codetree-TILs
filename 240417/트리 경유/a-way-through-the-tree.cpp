#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m;
int arr[1048577];
bool visited[1048577];

int dfs(int x){
    int ret = 0;
    while(x){
        if(visited[x]){
            ret = x;
        }
        x /= 2;
    }
    return ret;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    while(m--){
        int x; cin >> x;
        int ans = dfs(x);
        cout << ans << '\n';

        if(ans == 0){
            visited[x] = 1;
        }
    }
    return 0;
}