#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n, m;
vector<int> weight;
vector<int> price;
int arr[10001];

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
        int w, p;
        cin >> w >> p;
        weight.push_back(w);
        price.push_back(p);
    }
    init();

    for(int i = 1; i <= m; i++){
        for(int j = 0; j < n; j++){
            if(i >= weight[j]){
                if(i - weight[j] == INT_MIN){
                    continue;
                }
                arr[i] = max(arr[i], arr[i - weight[j]] + price[j]);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= m; i++){
        ans = max(ans, arr[i]);
    }
    cout << ans;
    return 0;
}