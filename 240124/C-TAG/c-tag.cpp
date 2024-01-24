// 50C3 -> 약 2만
// 2만 * 1000 -> 2천만 

#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int n, m, offset[3], cnt;
string a[1005], b[1005];

void backtracking(int curr, int last) {
    if(curr == 3) {

        // for(int i = 0; i < 3; ++i) cout << offset[i] << ' ';
        // cout << endl;

        unordered_set<string> all;

        unordered_set<string> arr;
        for(int j = 0; j < n; ++j) {
            string temp = "";
            for(int i = 0; i < 3; ++i) {
                temp += a[j][offset[i]];
            }
            arr.insert(temp);
            all.insert(temp);
        }


        unordered_set<string> arr2;
        for(int j = 0; j < n; ++j) {
            string temp = "";
            for(int i = 0; i < 3; ++i) {
                temp += b[j][offset[i]];
            }
            arr2.insert(temp);
            all.insert(temp);
        }
        
        // 두 개로 구분 된다 -> 두 개의 집합의 공집합이 0 이다.
        if(arr.size() + arr2.size() == all.size()) ++cnt;
        
        return;
    }

    // 선택 o
    for(int i = last + 1; i < m; ++i) {
        offset[curr] = i;
        backtracking(curr + 1, i);   
    }

}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    // input
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];
    
    // backtracking
    backtracking(0, -1);

    // output
    cout << cnt;

    return 0;
}