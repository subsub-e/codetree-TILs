#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n, m;
vector<int> v;
vector<int> wa;
int arr[10001];

void init(){
    for(int i = 0; i < m; i++){
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
                wa.push_back(arr[i - v[j]] + 1);
            }
        }
        if(wa.size() > 0){
            sort(wa.begin(), wa.end());
            // for(int k = 0; k < wa.size(); k++){
            //     cout << wa[k] << ' ';
            // }
            //cout << '\n';
            arr[i] = wa[0];
            wa.clear();
        }
    }
    if(arr[m] == INT_MIN || 0){
        cout << -1;
        return 0;
    }
    // for(int i = 0; i <= m; i++){
    //     cout << arr[i] << ' ';
    // }
    // cout << '\n';
    cout << arr[m];
    return 0;
}