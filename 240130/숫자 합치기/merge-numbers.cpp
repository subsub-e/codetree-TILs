#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int sum = 0;
    vector<int> v;
    int a; cin >> a;
    for(int i = 0; i < a; i++){
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int index = 0;
    for(int i = 0; i < a-1; i++){
        int p = v[index] + v[index + 1];
        v[index] = 0;
        v[index + 1] = 0;
        v.push_back(p);
        sum += p;
        sort(v.begin(), v.end());
        // for(int j = 0; j < v.size(); j++){
        //     cout << v[j] << ' '; 
        // }
        // cout << '\n';
        index += 2;
    }
    cout << sum;
    return 0;
}