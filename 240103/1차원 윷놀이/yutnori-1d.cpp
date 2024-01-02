#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, k;
int arr[100];
int ans;
vector<int> v;

int total(){
    int cnt = 0;
    int count[k + 1] = {};
    for(int i = 0; i < n; i++){
        count[v[i]] += arr[i];
    }
    for(int i = 1; i < k + 1; i++){
        if(count[i] >= m-1){
            cnt++;
        }
    }
    return cnt;
}

void simulate(int x){
    if(x == n + 1){
        ans = max(ans, total());
        return;
    }

    for(int i = 1; i <= k; i++){
        v.push_back(i);
        simulate(x + 1);
        v.pop_back();
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    simulate(1);
    cout << ans;
    return 0;
}