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
        arr[i] = INT_MAX;
    }
    arr[0] = 0;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    init();

    for(int i = 0; i < n; i++){
        for(int j = m; j > 0; j--){
            if(j >= v[i]){
                if(arr[j - v[i]] == INT_MAX){
                    continue;
                }
                arr[j] = min(arr[j], arr[j - v[i]] + 1);
            }
        }
        // for(int i = 0; i <= m; i++){
        //     cout << arr[i] << ' ';
        // }
        // cout << '\n';
        // cout << '\n';
        // cout << '\n';
    }
    
    if(arr[m] == INT_MAX){
        cout << -1;
        return 0;
    }
    cout << arr[m];
    return 0;
}