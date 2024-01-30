#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    vector<int> v;
    for(int i = 0; i < a; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    long long maxans = 0;
    long long sum = 0;
    for(int i = 1; i < a; i++){
        if(v[i] - v[i-1] < 0){
            sum = 0;
            continue;
        }
        sum += (v[i] - v[i - 1]);
        maxans = max(maxans, sum);
    }
    cout << maxans;
    return 0;
}