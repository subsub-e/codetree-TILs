#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a, coin; cin >> a >> coin;
    vector<int> v;
    int minans = INT_MAX;
    for(int i = 0; i < a; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    int cnt = 0;
    int index = a - 1;
    while(coin > 0){
        if(coin >= v[index]){
            cnt++;
            coin -= v[index];
        }
        else{
            index--;
        }
    }
    cout << cnt;
    return 0;
}