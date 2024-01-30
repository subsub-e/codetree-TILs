#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    vector<int> v;
    int sum = 0;
    int maxans = 0;
    for(int i = 0; i < a; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    for(int i = 0; i < a; i++){
        sum += v[i];
        maxans = max(maxans, sum);
        if(sum <= 0){
            sum = 0;
        }
    }
    cout << maxans;
    return 0;
}