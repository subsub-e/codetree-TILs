#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // 여기에 코드를 작성해주세요.
    int a, b; cin >> a >> b;
    int arr[100001];
    unordered_map<int, int> m;
    for(int i = 0; i < a; i++){
        cin >> arr[i];
        m[arr[i]]++;
    }
    int cnt = 0;
    for(int i = 0; i < a; i++){
        int d = b - arr[i];
        if(m.find(d) != m.end()){
            cnt += m[d];
        }
        m.erase(arr[i]);
    }
    cout << cnt;
    return 0;
}