#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int n, m;
int arr[10001];
vector<int> v;

void init(){
    for(int i = 0; i <= m; i++){
        arr[i] = INT_MIN;
    }
    arr[0] = 0;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int coin;
        cin >> coin;
        v.push_back(coin);
    }
    init();
    for(int i = 1; i <= m; i++){
        for(int j = 0; j < n; j++){
            if(i >= v[j]){
                if(arr[i - v[j]] == INT_MIN){
                    continue;
                }
                arr[i] = max(arr[i], arr[i - v[j]] + 1);
            }
        }
    }
    // for(int i = 0; i <= m; i++){
    //     cout << arr[i] << ' ';
    // }
    // cout << '\n';
    if(arr[m] == INT_MIN){
        cout << -1;
        return 0;
    }
    cout << arr[m];
    return 0;
}