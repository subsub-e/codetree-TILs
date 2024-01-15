#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    string arr[a];
    unordered_map<string, int> m;
    for(int i = 0; i < a; i++){
        cin >> arr[i];
        m[arr[i]]++;
    }
    int ans = 0;
    for(int i = 0; i < a; i++){
        ans = max(ans, m[arr[i]]);
    }
    cout << ans;
    return 0;
}