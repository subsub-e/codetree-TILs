#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a; cin >> a;
    int ans = 0;
    unordered_map<string, int> m;
    for(int i = 0; i < a; i++){
        string str; cin >> str;
        sort(str.begin(), str.end());
        m[str]++;
        ans = max(ans, m[str]);
    }
    cout << ans;
    
    return 0;
}